#!/usr/bin/python3
import binascii

testsets = [
    "ABC",
    "12345",
]

for data in testsets:
    crc = binascii.crc32(data.encode('utf-8'))
    print(data + ' : ' + hex(crc))
