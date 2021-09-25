#!/usr/bin/python3
import binascii
import zlib

testsets = [
    "ABC",
    "12345",
]

for data in testsets:
    crc = binascii.crc32(data.encode('utf-8'))
    crczlib = zlib.crc32(data.encode('utf-8'))
    print("[binascii] " + data + ' : ' + hex(crc))
    print("[zlib]     " + data + ' : ' + hex(crczlib))

