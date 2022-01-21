import math


def translate(byte_string, L):
    seperated = []
    for i in range(0, len(byte_string), 2):
        seperated.append(byte_string[i: i + 2])
    for i, bit in enumerate(seperated):
        if (bit == '00'):
            seperated[i] = 'A'
        elif (bit == '01'):
            seperated[i] = 'C'
        elif (bit == '10'):
            seperated[i] = 'G'
        elif (bit == '11'):
            seperated[i] = 'T'
    print("".join(seperated[:int(L)]))


byte_array = bytearray()
with open("input.txt", "rb") as f:
    while (byte := f.read(1)):
        byte_array += byte
position = 0
T = ''

for i, byte in enumerate(byte_array[position:]):
    if byte == 10:
        position = i + 1
        print(T)
        break
    else:
        T += chr(byte)
        continue

for i in range(int(T)):
    N = ''
    for i, byte in enumerate(byte_array[position:]):
        if (byte == 32):
            position += i + 1
            print(N, end=" ")
            break
        else:
            N += chr(byte)
            continue

    K = ''
    for i, byte in enumerate(byte_array[position:]):
        if (byte == 10):
            position += i + 1
            print(K)
            break
        else:
            K += chr(byte)
            continue

    for i in range(int(N)):
        L = ''
        retezec = []
        for i, byte in enumerate(byte_array[position:]):
            if (byte == 32):
                position += i + 1
                print(L, end=" ")
                break
            else:
                L += chr(byte)
                continue

        for i, byte in enumerate(byte_array[position:position+math.ceil(int(L)/4)]):
            position += 1
            retezec.append(byte)
        position += 1
        translate("".join([bin(byte)[2:].zfill(8) for byte in retezec]), L)
