# Descripción de los paquetes

## ⛔ NOTA
Considerar que en cada uno de los paquetes proporcionados, los primeros 14 bytes, corresponden al encabezado de la capa de red.

## UDP localhost
```
Ethernet II, Src: 00:00:00_00:00:00 (00:00:00:00:00:00), Dst: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Destination: 00:00:00_00:00:00 (00:00:00:00:00:00)
        Address: 00:00:00_00:00:00 (00:00:00:00:00:00)
        .... ..0. .... .... .... .... = LG bit: Globally unique address (factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Source: 00:00:00_00:00:00 (00:00:00:00:00:00)
        Address: 00:00:00_00:00:00 (00:00:00:00:00:00)
        .... ..0. .... .... .... .... = LG bit: Globally unique address (factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Type: IPv4 (0x0800)
Internet Protocol Version 4, Src: 127.0.0.1, Dst: 127.0.0.1
    0100 .... = Version: 4
    .... 0101 = Header Length: 20 bytes (5)
    Differentiated Services Field: 0x00 (DSCP: CS0, ECN: Not-ECT)
        0000 00.. = Differentiated Services Codepoint: Default (0)
        .... ..00 = Explicit Congestion Notification: Not ECN-Capable Transport (0)
    Total Length: 41
    Identification: 0xc7cc (51148)
    Flags: 0x4000, Don't fragment
        0... .... .... .... = Reserved bit: Not set
        .1.. .... .... .... = Don't fragment: Set
        ..0. .... .... .... = More fragments: Not set
    Fragment offset: 0
    Time to live: 64
    Protocol: UDP (17)
    Header checksum: 0x74f5 [validation disabled]
    [Header checksum status: Unverified]
    Source: 127.0.0.1
    Destination: 127.0.0.1
User Datagram Protocol, Src Port: 59520, Dst Port: 10000
    Source Port: 59520
    Destination Port: 10000
    Length: 21
    Checksum: 0xfe28 [unverified]
    [Checksum Status: Unverified]
    [Stream index: 1410]
    [Timestamps]
        [Time since first frame: 0.000000000 seconds]
        [Time since previous frame: 0.000000000 seconds]
Data (13 bytes)
    Data: 68656c6c6f20776f726c64212e
    [Length: 13]

0000  00 00 00 00 00 00 00 00 00 00 00 00 08 00 45 00   ..............E.
0010  00 29 c7 cc 40 00 40 11 74 f5 7f 00 00 01 7f 00   .)..@.@.t.......
0020  00 01 e8 80 27 10 00 15 fe 28 68 65 6c 6c 6f 20   ....'....(hello
0030  77 6f 72 6c 64 21 2e                              world!.
```

## TCP localhost
```
Ethernet II, Src: 00:00:00_00:00:00 (00:00:00:00:00:00), Dst: 00:00:00_00:00:00 (00:00:00:00:00:00)
    Destination: 00:00:00_00:00:00 (00:00:00:00:00:00)
        Address: 00:00:00_00:00:00 (00:00:00:00:00:00)
        .... ..0. .... .... .... .... = LG bit: Globally unique address (factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Source: 00:00:00_00:00:00 (00:00:00:00:00:00)
        Address: 00:00:00_00:00:00 (00:00:00:00:00:00)
        .... ..0. .... .... .... .... = LG bit: Globally unique address (factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Type: IPv4 (0x0800)
Internet Protocol Version 4, Src: 127.0.0.1, Dst: 127.0.0.1
    0100 .... = Version: 4
    .... 0101 = Header Length: 20 bytes (5)
    Differentiated Services Field: 0x00 (DSCP: CS0, ECN: Not-ECT)
        0000 00.. = Differentiated Services Codepoint: Default (0)
        .... ..00 = Explicit Congestion Notification: Not ECN-Capable Transport (0)
    Total Length: 65
    Identification: 0x2338 (9016)
    Flags: 0x4000, Don't fragment
        0... .... .... .... = Reserved bit: Not set
        .1.. .... .... .... = Don't fragment: Set
        ..0. .... .... .... = More fragments: Not set
    Fragment offset: 0
    Time to live: 64
    Protocol: TCP (6)
    Header checksum: 0x197d [validation disabled]
    [Header checksum status: Unverified]
    Source: 127.0.0.1
    Destination: 127.0.0.1
Transmission Control Protocol, Src Port: 48864, Dst Port: 10000, Seq: 1, Ack: 1, Len: 13
    Source Port: 48864
    Destination Port: 10000
    [Stream index: 0]
    [TCP Segment Len: 13]
    Sequence number: 1    (relative sequence number)
    Sequence number (raw): 1746091235
    [Next sequence number: 14    (relative sequence number)]
    Acknowledgment number: 1    (relative ack number)
    Acknowledgment number (raw): 3673809643
    1000 .... = Header Length: 32 bytes (8)
    Flags: 0x018 (PSH, ACK)
        000. .... .... = Reserved: Not set
        ...0 .... .... = Nonce: Not set
        .... 0... .... = Congestion Window Reduced (CWR): Not set
        .... .0.. .... = ECN-Echo: Not set
        .... ..0. .... = Urgent: Not set
        .... ...1 .... = Acknowledgment: Set
        .... .... 1... = Push: Set
        .... .... .0.. = Reset: Not set
        .... .... ..0. = Syn: Not set
        .... .... ...0 = Fin: Not set
        [TCP Flags: ·······AP···]
    Window size value: 512
    [Calculated window size: 65536]
    [Window size scaling factor: 128]
    Checksum: 0xfe35 [unverified]
    [Checksum Status: Unverified]
    Urgent pointer: 0
    Options: (12 bytes), No-Operation (NOP), No-Operation (NOP), Timestamps
        TCP Option - No-Operation (NOP)
            Kind: No-Operation (1)
        TCP Option - No-Operation (NOP)
            Kind: No-Operation (1)
        TCP Option - Timestamps: TSval 888986650, TSecr 888986650
            Kind: Time Stamp Option (8)
            Length: 10
            Timestamp value: 888986650
            Timestamp echo reply: 888986650
    [SEQ/ACK analysis]
        [iRTT: 0.000029199 seconds]
        [Bytes in flight: 13]
        [Bytes sent since last PSH flag: 13]
    [Timestamps]
        [Time since first frame in this TCP stream: 0.000057798 seconds]
        [Time since previous frame in this TCP stream: 0.000028599 seconds]
    TCP payload (13 bytes)
Data (13 bytes)
    Data: 48656c6c6f2c20576f726c6421
    [Length: 13]

0000  00 00 00 00 00 00 00 00 00 00 00 00 08 00 45 00   ..............E.
0010  00 41 23 38 40 00 40 06 19 7d 7f 00 00 01 7f 00   .A#8@.@..}......
0020  00 01 be e0 27 10 68 13 3c e3 da f9 e2 eb 80 18   ....'.h.<.......
0030  02 00 fe 35 00 00 01 01 08 0a 34 fc dc 1a 34 fc   ...5......4...4.
0040  dc 1a 48 65 6c 6c 6f 2c 20 57 6f 72 6c 64 21      ..Hello, World!

```

### UDP WAN
```
Ethernet II, Src: IntelCor_50:82:ff (7c:2a:31:50:82:ff), Dst: 52:02:71:8b:f2:70 (52:02:71:8b:f2:70)
    Destination: 52:02:71:8b:f2:70 (52:02:71:8b:f2:70)
        Address: 52:02:71:8b:f2:70 (52:02:71:8b:f2:70)
        .... ..1. .... .... .... .... = LG bit: Locally administered address (this is NOT the factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Source: IntelCor_50:82:ff (7c:2a:31:50:82:ff)
        Address: IntelCor_50:82:ff (7c:2a:31:50:82:ff)
        .... ..0. .... .... .... .... = LG bit: Globally unique address (factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Type: IPv4 (0x0800)
Internet Protocol Version 4, Src: 192.168.15.22, Dst: 142.251.40.67
    0100 .... = Version: 4
    .... 0101 = Header Length: 20 bytes (5)
    Differentiated Services Field: 0x00 (DSCP: CS0, ECN: Not-ECT)
        0000 00.. = Differentiated Services Codepoint: Default (0)
        .... ..00 = Explicit Congestion Notification: Not ECN-Capable Transport (0)
    Total Length: 559
    Identification: 0xe663 (58979)
    Flags: 0x4000, Don't fragment
        0... .... .... .... = Reserved bit: Not set
        .1.. .... .... .... = Don't fragment: Set
        ..0. .... .... .... = More fragments: Not set
    Fragment offset: 0
    Time to live: 64
    Protocol: UDP (17)
    Header checksum: 0xcb5d [validation disabled]
    [Header checksum status: Unverified]
    Source: 192.168.15.22
    Destination: 142.251.40.67
User Datagram Protocol, Src Port: 53762, Dst Port: 443
    Source Port: 53762
    Destination Port: 443
    Length: 539
    Checksum: 0x1d74 [unverified]
    [Checksum Status: Unverified]
    [Stream index: 71]
    [Timestamps]
        [Time since first frame: 0.001427724 seconds]
        [Time since previous frame: 0.000605826 seconds]
Data (531 bytes)
    Data: d800000001083db704051345e4d200420200300bd26e5b52…
    [Length: 531]

0000  52 02 71 8b f2 70 7c 2a 31 50 82 ff 08 00 45 00   R.q..p|*1P....E.
0010  02 2f e6 63 40 00 40 11 cb 5d c0 a8 0f 16 8e fb   ./.c@.@..]......
0020  28 43 d2 02 01 bb 02 1b 1d 74 d8 00 00 00 01 08   (C.......t......
0030  3d b7 04 05 13 45 e4 d2 00 42 02 00 30 0b d2 6e   =....E...B..0..n
0040  5b 52 b8 55 7b 97 20 8f bd 40 05 ce e5 61 08 19   [R.U{. ..@...a..
0050  d3 70 43 83 51 c0 97 a8 f4 bf 0f 03 b1 5d 86 fb   .pC.Q........]..
0060  96 e7 05 34 b1 65 c5 a1 d4 59 79 6b 32 62 22 9d   ...4.e...Yyk2b".
0070  fb 03 c2 5e 36 75 1f 1d 62 cf f3 93 6b 9a fa a5   ...^6u..b...k...
0080  b4 43 66 5d 5e 55 1f 90 50 2a b9 1c 7a c3 1f 97   .Cf]^U..P*..z...
0090  97 4c bf f4 7e d8 09 89 82 24 9a ac d8 e6 3d 2c   .L..~....$....=,
00a0  15 ac 84 5d c2 24 80 64 51 40 11 ef 8c f4 3e ba   ...].$.dQ@....>.
00b0  de dc 56 d3 0f 2f 16 53 21 44 01 2f 66 8a 1c 0d   ..V../.S!D./f...
00c0  70 d8 1b e1 e2 b2 a7 ee 2f b2 ab 01 5a 37 7d 9e   p......./...Z7}.
00d0  2d ee d8 bf be f6 04 6c 4e ca 49 7c 9b de 9a d6   -......lN.I|....
00e0  41 99 ed cf 71 ab 8e c4 62 23 65 3f b0 7f 1c e4   A...q...b#e?....
00f0  55 ee 5c fa 5a 6c 87 c9 0e 61 ab fd f1 06 dd 8c   U.\.Zl...a......
0100  9b 74 84 2c 56 6e 53 7e 38 a6 07 d3 95 bf 0c 3b   .t.,VnS~8......;
0110  88 f1 8d b3 5a ff 01 a7 45 19 d1 2a 5f 84 40 25   ....Z...E..*_.@%
0120  f1 e6 88 6b c2 df db e1 3f 18 16 29 c0 a4 f3 02   ...k....?..)....
0130  e6 22 3e f1 fe 8e 0e 01 37 db fb 60 eb 20 a6 c4   .">.....7..`. ..
0140  af fa 7a e9 67 a6 b3 2c 8b a5 d2 c7 eb 34 ca 0b   ..z.g..,.....4..
0150  30 e6 db e6 43 ce 54 46 64 dd 0f 50 4a f5 56 40   0...C.TFd..PJ.V@
0160  16 00 5c ad 00 53 c5 36 ce 4b b4 06 df 8c 1b db   ..\..S.6.K......
0170  79 53 6e c4 9c 5b 47 af 60 0f 10 ed b8 33 f5 02   ySn..[G.`....3..
0180  28 73 9b ed 3f 7f 26 b4 c5 ae 9a 01 8b c8 5c ae   (s..?.&.......\.
0190  70 52 a1 67 cb 96 e0 45 1d b0 ff 34 42 d8 cd 39   pR.g...E...4B..9
01a0  29 fa ab 56 af 16 31 41 7f 26 6d 68 1c 66 ab 9f   )..V..1A.&mh.f..
01b0  c7 e8 bb fc 13 7c c4 8c ea 6f ef d7 82 42 4a 0f   .....|...o...BJ.
01c0  0b 2e 96 a5 2d e4 90 11 f0 6c 63 bb a0 e7 3d 31   ....-....lc...=1
01d0  6c 05 79 d4 70 2a c1 dd dc 55 91 25 2f cc df a2   l.y.p*...U.%/...
01e0  7f 9b 04 97 20 c0 ca 0f f1 97 4c a1 03 ae 72 12   .... .....L...r.
01f0  ff e2 19 db 93 69 b0 e8 bb 5f d8 ab 5e ae 2f 9d   .....i..._..^./.
0200  6b 0e b4 10 46 47 f9 54 76 c7 e0 1a 8d 9e dc c8   k...FG.Tv.......
0210  ed e7 cf 72 ae 77 fd da 55 56 2b 26 cc 42 bd 7e   ...r.w..UV+&.B.~
0220  d4 15 9a ce 31 4d 51 62 dd b1 52 01 47 6d 70 04   ....1MQb..R.Gmp.
0230  ca 1b d0 06 ba f5 24 a0 b0 2e 9a d4 42            ......$.....B
```

## TCP WAN
```
Ethernet II, Src: IntelCor_50:82:ff (7c:2a:31:50:82:ff), Dst: 52:02:71:8b:f2:70 (52:02:71:8b:f2:70)
    Destination: 52:02:71:8b:f2:70 (52:02:71:8b:f2:70)
        Address: 52:02:71:8b:f2:70 (52:02:71:8b:f2:70)
        .... ..1. .... .... .... .... = LG bit: Locally administered address (this is NOT the factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Source: IntelCor_50:82:ff (7c:2a:31:50:82:ff)
        Address: IntelCor_50:82:ff (7c:2a:31:50:82:ff)
        .... ..0. .... .... .... .... = LG bit: Globally unique address (factory default)
        .... ...0 .... .... .... .... = IG bit: Individual address (unicast)
    Type: IPv4 (0x0800)
Internet Protocol Version 4, Src: 192.168.15.22, Dst: 216.219.115.8
    0100 .... = Version: 4
    .... 0101 = Header Length: 20 bytes (5)
    Differentiated Services Field: 0x00 (DSCP: CS0, ECN: Not-ECT)
        0000 00.. = Differentiated Services Codepoint: Default (0)
        .... ..00 = Explicit Congestion Notification: Not ECN-Capable Transport (0)
    Total Length: 156
    Identification: 0x1685 (5765)
    Flags: 0x4000, Don't fragment
        0... .... .... .... = Reserved bit: Not set
        .1.. .... .... .... = Don't fragment: Set
        ..0. .... .... .... = More fragments: Not set
    Fragment offset: 0
    Time to live: 64
    Protocol: TCP (6)
    Header checksum: 0x0835 [validation disabled]
    [Header checksum status: Unverified]
    Source: 192.168.15.22
    Destination: 216.219.115.8
Transmission Control Protocol, Src Port: 51314, Dst Port: 12975, Seq: 1, Ack: 1, Len: 104
    Source Port: 51314
    Destination Port: 12975
    [Stream index: 5]
    [TCP Segment Len: 104]
    Sequence number: 1    (relative sequence number)
    Sequence number (raw): 3769615692
    [Next sequence number: 105    (relative sequence number)]
    Acknowledgment number: 1    (relative ack number)
    Acknowledgment number (raw): 3453808317
    1000 .... = Header Length: 32 bytes (8)
    Flags: 0x018 (PSH, ACK)
        000. .... .... = Reserved: Not set
        ...0 .... .... = Nonce: Not set
        .... 0... .... = Congestion Window Reduced (CWR): Not set
        .... .0.. .... = ECN-Echo: Not set
        .... ..0. .... = Urgent: Not set
        .... ...1 .... = Acknowledgment: Set
        .... .... 1... = Push: Set
        .... .... .0.. = Reset: Not set
        .... .... ..0. = Syn: Not set
        .... .... ...0 = Fin: Not set
        [TCP Flags: ·······AP···]
    Window size value: 501
    [Calculated window size: 501]
    [Window size scaling factor: -1 (unknown)]
    Checksum: 0xb95b [unverified]
    [Checksum Status: Unverified]
    Urgent pointer: 0
    Options: (12 bytes), No-Operation (NOP), No-Operation (NOP), Timestamps
        TCP Option - No-Operation (NOP)
            Kind: No-Operation (1)
        TCP Option - No-Operation (NOP)
            Kind: No-Operation (1)
        TCP Option - Timestamps: TSval 2052989392, TSecr 3778902533
            Kind: Time Stamp Option (8)
            Length: 10
            Timestamp value: 2052989392
            Timestamp echo reply: 3778902533
    [SEQ/ACK analysis]
        [Bytes in flight: 104]
        [Bytes sent since last PSH flag: 104]
    [Timestamps]
        [Time since first frame in this TCP stream: 0.000000000 seconds]
        [Time since previous frame in this TCP stream: 0.000000000 seconds]
    TCP payload (104 bytes)
Data (104 bytes)
    Data: 00000064000000a6c64b9ee2b2d291331a1206ce5099a333…
    [Length: 104]

0000  52 02 71 8b f2 70 7c 2a 31 50 82 ff 08 00 45 00   R.q..p|*1P....E.
0010  00 9c 16 85 40 00 40 06 08 35 c0 a8 0f 16 d8 db   ....@.@..5......
0020  73 08 c8 72 32 af e0 af c5 4c cd dc ee bd 80 18   s..r2....L......
0030  01 f5 b9 5b 00 00 01 01 08 0a 7a 5e 21 d0 e1 3d   ...[......z^!..=
0040  7a 05 00 00 00 64 00 00 00 a6 c6 4b 9e e2 b2 d2   z....d.....K....
0050  91 33 1a 12 06 ce 50 99 a3 33 30 6e 81 ee a5 56   .3....P..30n...V
0060  41 23 36 a6 d0 d7 2a b5 6a a6 3f 40 ef bd 0f b4   A#6...*.j.?@....
0070  f1 71 54 47 0c 6e 7d ce 1c 81 9e a5 58 19 91 00   .qTG.n}.....X...
0080  17 d5 42 e8 07 b0 f6 53 4c e5 9a 8d 00 3f 12 d6   ..B....SL....?..
0090  71 d0 1f ad 76 83 72 55 5e 94 99 f8 78 a2 e5 b4   q...v.rU^...x...
00a0  26 88 fe a6 07 69 e4 f6 6c 97                     &....i..l.
```
