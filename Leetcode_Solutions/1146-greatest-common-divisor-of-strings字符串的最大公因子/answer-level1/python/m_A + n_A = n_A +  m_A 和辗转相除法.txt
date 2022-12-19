### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1 + str2 != str2 + str1:
            return ""
        long1 = len(str1)
        long2 = len(str2)
        m, n = max(long1,long2), min(long1,long2)
        while m%n !=0:
            m, n = n, m%n
        return str1[:n]
        
```