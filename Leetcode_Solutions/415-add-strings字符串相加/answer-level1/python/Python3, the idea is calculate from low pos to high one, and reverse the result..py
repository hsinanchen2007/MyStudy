```python3
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        if not num1 or not num2:
            return num1 or num2
        num1 = num1[::-1]
        num2 = num2[::-1]
        flag = 0
        res = ""
        while num1 or num2 or flag:
            v1 = v2 = 0
            if num1:
                v1 = int(num1[0])
                num1 = num1[1:]
            if num2:
                v2 = int(num2[0])
                num2 = num2[1:]
            cur = v1+v2+flag
            flag = 0
            if cur >= 10:
                cur -= 10
                flag = 1
            res += str(cur)
        return res[::-1]