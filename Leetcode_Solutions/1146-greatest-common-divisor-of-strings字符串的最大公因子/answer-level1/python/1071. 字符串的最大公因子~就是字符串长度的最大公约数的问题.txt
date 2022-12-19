### 解题思路
对长度进行最大公约数即可！但是前提是保证有X的情况下


### 代码

```python3
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1 + str2 != str2 + str1:
            return ''
        
        len1 = len(str1)
        len2 = len(str2)

        if len1 < len2:
            len1, len2 = len2, len1
        
        while len1 % len2 != 0:
            len1, len2 = len2, len1%len2
        
        return str1[:len2]

        
        
```