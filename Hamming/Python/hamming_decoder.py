print('Enter the hamming code received')
pot2 = [1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048]
d = input()
data = list(d)
data.reverse()
c, ch, j, r, error, h, parity_list, h_copy = 0, 0, 0, 0, 0, [], [], []
num = ''
h_num = ''

for k in range(0, len(data)):
    p = (2 ** c)
    h.append(int(data[k]))
    h_copy.append(data[k])
    if p == (k + 1):
        c = c + 1

for parity in range(0, (len(h))):
    ph = (2 ** ch)
    if ph == (parity + 1):

        startIndex = ph - 1
        i = startIndex
        toXor = []

        while i < len(h):
            block = h[i:i + ph]
            toXor.extend(block)
            i += 2 * ph

        for z in range(1, len(toXor)):
            h[startIndex] = h[startIndex] ^ toXor[z]
        parity_list.append(h[parity])
        ch += 1

parity_list.reverse()

error = sum(int(parity_list)*(2 ** i) for i,
            parity_list in enumerate(parity_list[::-1]))

if error == 0:
    print('There is no error in Hamming code')
    for i in range(len(d)):
        if not (i in pot2):
            num += d[i]
        
    itg = int(num, 2)

    print('the number you inserted before decode is: ', itg)


elif error >= len(h_copy):
    print('Error cannot be detected')

else:
    print('Error is in', error, 'bit')

    if h_copy[error - 1] == '0':
        h_copy[error - 1] = '1'

    elif h_copy[error - 1] == '1':
        h_copy[error - 1] = '0'
        print('After correction hamming code is:- ', end='')
    h_copy.reverse()
    print(int(''.join(map(str, h_copy))))

    for i in range(len(d)):

        if not(i in pot2):
            num += d[i]
            h_num = h_num.__add__(h_copy[i])

    itg = int(num, 2)

    h_itg = int(h_num, 2)

    print('the number you inserted before decode is: ', itg)
    print('the number which hamming get is: ', h_itg)


