```
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        len1 = len(num1)
        len2 = len(num2)
        res = ['0'] * (len1 + len2)  # 关键步骤
        for i in range(len1-1, -1, -1):
            for j in range(len2-1, -1, -1):
                tmp = int(num2[j]) * int(num1[i]) + int(res[i+j+1])
                res[i+j+1] = str(tmp%10)
                res[i+j] = str(int(res[i+j]) + tmp // 10)
                
        for i in range(len1+len2):
            if res[i] != '0':
                return ''.join(res[i:])
        return '0'
```