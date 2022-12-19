```
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        if len(a) < len(b):
            a, b = b, a
        for i in range(-1, -1 - len(b), -1):
            if b[i] == '1':
                j = i
                while(j >= -len(a)):
                    if a[j] == '0':
                        a = a[:len(a) + j] + '1' + a[len(a) + j + 1:]
                        break
                    else:
                        a = a[:len(a) + j] + '0' + a[len(a) + j + 1:]
                        j -= 1
                if j == -1 - len(a):
                    a = '1' + a
        return a
```