#善于利用ord和chr
```
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        ret = ''
        up = 0#进位
        i, j, carry = len(num1) - 1, len(num2) - 1, 0
        while i >= 0 or j >= 0:
            n1 = ord(num1[i]) - ord('0') if i >= 0 else 0
            n2 = ord(num2[j]) - ord('0') if j >= 0 else 0
            temp = n1 + n2 + up
            up = temp // 10
            ret = chr(temp % 10 + ord('0')) + ret
            i -= 1
            j -= 1
        return ret if up == 0 else chr(up + ord('0')) + ret
```
