### 解题思路
求最大公因子等价于求最大公约数，然后判断公约数长度的字符串是否为其公因子。
### 代码

```python3
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        def getgcd(a, b):
            if a < b:
                a, b = b, a
            while a % b:
                a, b = b, a%b
            return b
        if str1+str2 == str2+str1:
            return str1[:getgcd(len(str1), len(str2))]
        return ""
```