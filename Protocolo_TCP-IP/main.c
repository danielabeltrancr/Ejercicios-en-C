#include <stdio.h>
#include <stdlib.h>

#define ERROR_NOFILE 1

// Estructura para el encabezado de IP
struct ip_header {
    unsigned char version_headerLength;       // Versión (4 bits) + longitud de la cabecera IP (4 bits)
    unsigned char type_of_service;            // Tipo de servicio (8 bits)
    unsigned short totalLength;               // Longitud total (16 bits)
    unsigned short identification;            // Identificación (16 bits)
    unsigned short flags_fragmentOffset;      // Banderas y offset de fragmento juntos (16 bits)
    unsigned char timeToLive;                 // Tiempo de vida (8 bits)
    unsigned char protocol;                   // Protocolo (8 bits)    
    unsigned short headerChecksum;            // Suma de control de la cabecera (16 bits)
    unsigned int sourceAddress;               // Dirección IP de origen (32 bits)
    unsigned int destinationAddress;          // Dirección IP de destino (32 bits)
};

// Estructura para el encabezado de TCP
struct tcp_header {
    unsigned short source_port;               // Puerto de origen (16 bits)
    unsigned short destination_port;          // Puerto de destino (16 bits)
    unsigned int sequence;                    // Número de secuencia (32 bits)
    unsigned int ack;                         // Número de ACK (32 bits)
    unsigned char header_len;                 // Longitud de la cabecera y reservado (8 bits)
    unsigned char flags;                      // Banderas (8 bits)
    unsigned short window;                    // Tamaño de ventana (16 bits)
    unsigned short checksum;                  // Suma de verificación (16 bits)
    unsigned short urgent_ptr;                // Puntero urgente (16 bits)
};

// Estructura para el encabezado de UDP
struct udp_header {
    unsigned short source_port;               // Puerto de origen (16 bits)
    unsigned short destination_port;          // Puerto de destino (16 bits)
    unsigned short length;                    // Longitud del mensaje (16 bits)
    unsigned short checksum;                  // Suma de verificación (16 bits)
};

int main(int argc, char* argv[]) {
    FILE *fData;
    int lenData = 0;
    unsigned char data[1516];        //1500, 1516

    // Abrir el archivo que contiene el paquete TCP/IP
    if (argc > 1) {
        printf("%s \n", argv[1]);
        fData = fopen(argv[1], "rb");
    } else {
        printf("%s \n", "No file");
        return ERROR_NOFILE;
    }

    //lenData = fread(data, 1, 1500, fData);
    //printf("len data %d \n", lenData);

    // Leer los primeros 14 bytes correspondientes al encabezado Ethernet y descartarlos
    lenData = fread(data, 1, 14, fData);
    if (lenData != 14) {
        printf("Error al leer el encabezado Ethernet\n");
        return 1;
    }
    // Saltar los primeros 14 bytes del encabezado Ethernet
    fseek(fData, 14, SEEK_SET);

    // Leer los primeros 20 bytes del encabezado IP
    lenData = fread(data, 1, 20, fData);
    if (lenData != 20) {
        printf("Error al leer el encabezado IP\n");
        return 1;
    }

    // Extraer los campos del encabezado IP
    struct ip_header ip;
    ip.version_headerLength = data[0];
    ip.type_of_service = data[1];
    ip.totalLength = data[2] << 8 | data[3];
    ip.identification = data[4] << 8 | data[5];
    ip.flags_fragmentOffset = data[6] << 8 | data[7];
    ip.timeToLive = data[8];
    ip.protocol = data[9];
    ip.headerChecksum = data[10] << 8 | data[11];
    ip.sourceAddress = data[12] << 24 | data[13] << 16 | data[14] << 8 | data[15];
    ip.destinationAddress = data[16] << 24 | data[17] << 16 | data[18] << 8 | data[19];

    // Imprimir los campos del encabezado IP
    printf("Encabezado IP:\n");
    printf("Versión: %d\n", (ip.version_headerLength >> 4) & 0x0F);                      // Versión de IP (nibble superior)
    printf("Longitud de la cabecera: %d bytes\n", (ip.version_headerLength & 0x0F) * 4); // Longitud de la cabecera (nibble inferior)
    printf("Longitud total: %d bytes\n", ip.totalLength);
    printf("Protocolo: %d\n", ip.protocol);
    printf("Suma de control de la cabecera: 0x%04X\n", ip.headerChecksum);
    printf("Dirección IP de origen: %d.%d.%d.%d\n",
           (ip.sourceAddress >> 24) & 0xFF, (ip.sourceAddress >> 16) & 0xFF,
           (ip.sourceAddress >> 8) & 0xFF, ip.sourceAddress & 0xFF);
    printf("Dirección IP de destino: %d.%d.%d.%d\n",
           (ip.destinationAddress >> 24) & 0xFF, (ip.destinationAddress >> 16) & 0xFF,
           (ip.destinationAddress >> 8) & 0xFF, ip.destinationAddress & 0xFF);
    printf("\n");

    // Leer el encabezado TCP o UDP dependiendo del protocolo
    if (ip.protocol == 6) {
        // Leer los primeros 20 bytes del encabezado TCP
        lenData = fread(data, 1, 20, fData);
        if (lenData != 20) {
            printf("Error al leer el encabezado TCP\n");
            return 1;
        }

        // Extraer los campos del encabezado TCP
        struct tcp_header tcp;
        tcp.source_port = (data[0] << 8) | data[1];
        tcp.destination_port = (data[2] << 8) | data[3];
        tcp.sequence = (data[4] << 24) | (data[5] << 16) | (data[6] << 8) | data[7];
        tcp.ack = (data[8] << 24) | (data[9] << 16) | (data[10] << 8) | data[11];
        tcp.header_len = (data[12] >> 4) * 4; // La longitud de la cabecera está en palabras de 32 bits
        tcp.flags = data[13];
        tcp.checksum = (data[16] << 8) | data[17];

        // Imprimir los campos del encabezado TCP
        printf("Encabezado TCP:\n");
        printf("Puerto de origen: %d\n", tcp.source_port);
        printf("Puerto de destino: %d\n", tcp.destination_port);
        printf("Número de secuencia: %u\n", tcp.sequence);
        printf("Número de ACK: %u\n", tcp.ack);
        printf("Longitud de cabecera: %d\n", tcp.header_len);
        printf("Control: 0x%02X\n", tcp.flags);
        printf("Suma de control: 0x%04X\n", tcp.checksum);
        printf("\n");

        // Leer los siguientes bytes correspondientes a los datos del segmento TCP
        lenData = fread(data, 1, ip.totalLength - (14 + ip.totalLength + tcp.header_len), fData);
        if (lenData < 0) {
            printf("Error al leer los datos del segmento TCP\n");
            return 1;
        }

        printf("Datos del segmento TCP:\n");
        fwrite(data, 1, lenData, stdout);
        printf("\n");
    }
    
    // UDP
    else if (ip.protocol == 17) {
        // Leer los siguientes 8 bytes correspondientes al encabezado UDP
        lenData = fread(data, 1, 8, fData);
        if (lenData != 8) {
            printf("Error al leer el encabezado UDP\n");
            return 1;
        }

        // Extraer los campos del encabezado TCP
        struct udp_header udp;
        udp.source_port = (data[0] << 8) | data[1];
        udp.destination_port = (data[2] << 8) | data[3];
        udp.length = (data[4] << 8) | data[5];
        udp.checksum = (data[6] << 8) | data[7];

        printf("Encabezado UDP:\n");
        printf("Puerto de origen: %d\n", udp.source_port);
        printf("Puerto de destino: %d\n", udp.destination_port);
        printf("Longitud del mensaje: %d\n", udp.length);
        printf("Suma de verificación: 0x%04X\n", udp.checksum);

        // Leer los siguientes bytes correspondientes a los datos del mensaje UDP
        lenData = fread(data, 1, udp.length - 8, fData);
        if (lenData < 0) {
            printf("Error al leer los datos del mensaje UDP\n");
            return 1;
        }

        printf("Datos del mensaje UDP:\n");
        fwrite(data, 1, lenData, stdout);
        printf("\n");
    }

    fclose(fData);           // Cerrar el archivo

    return 0;
}
