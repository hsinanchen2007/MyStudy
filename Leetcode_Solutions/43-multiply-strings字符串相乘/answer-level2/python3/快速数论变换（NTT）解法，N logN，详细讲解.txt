```
class Solution(object):
    def multiply(self, num1: str, num2: str) -> str:
        if not num1 or not num2: return 0

        A = [int(i) for i in num1[::-1]]
        B = [int(i) for i in num2[::-1]]
        lenA, lenB = len(A), len(B)
        if lenA + lenB < 3: str(A[0]*B[0])
            
        length = lenA + lenB - 1
        l, n = 0, 1
        while n < length: l, n = l + 1, n << 1

        A += [0]*(n-lenA)
        B += [0]*(n-lenB)
        ntt(A)
        ntt(B)

        C = [A[i]*B[i] % mod for i in range(n)]
        ntt(C, -1)
        C = [i>>l for i in C[:length]]

        carry = i = 0
        while i < len(C):
            num = C[i] + carry
            C[i] = num % 10
            carry = num // 10
            if i >= len(C)-1 and carry:
                C.append(carry)
                carry = 0
            i += 1

        while C and C[-1] == 0: C.pop()

        return ''.join([str(i) for i in C[::-1]])
```
其中ntt函数是进行数论变换，介于篇幅过长，就只贴链接了：[快速数论变换（NTT）及蝴蝶操作构造详解](https://zhuanlan.zhihu.com/p/80297169)