### 解题思路
标准加法进位，主要理解一下ASCII转换。

### 代码

```python
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        i = len(num1)-1
        j = len(num2)-1
        res = ""
        carry = 0
        while i >=0 or j >= 0:
            n1 = num1[i] if i >= 0 else '0'
            n2 = num2[j] if j >= 0 else '0'
            temp = ord(n1) + ord(n2) - 2*ord('0') + carry
            cur = temp%10 
            carry = temp//10
            res = chr(cur+48) + res
            i -= 1
            j -= 1 
        return '1' + res if carry != 0 else res
        
```