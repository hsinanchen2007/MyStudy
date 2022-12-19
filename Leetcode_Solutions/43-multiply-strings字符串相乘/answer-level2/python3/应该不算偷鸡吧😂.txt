```
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        num1 = list(num1)
        num2 = list(num2)
        res = []
        for i in range(len(num2)-1,-1,-1):
            tmp = 0
            s = ''
            for j in range(len(num1)-1,-1,-1):
                a = int(num1[j]) * int(num2[i])
                a += tmp
                s = str(a%10) + s
                tmp = a//10
            if tmp != 0:
                s = str(tmp) + s
            s += '0'*(len(num2)-1-i)
            res.append(s)
        ans = 0
        for item in res:
            ans += int(item)
        return str(ans)
```
