### 解题思路
若两个字符串存在最大公约字符串，则s1+s2=s2+s1,且长度为两者长度的最大公约数

### 代码

```python3
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1+str2!=str2+str1:
            return ''
        return str1[:math.gcd(len(str1),len(str2))]
```