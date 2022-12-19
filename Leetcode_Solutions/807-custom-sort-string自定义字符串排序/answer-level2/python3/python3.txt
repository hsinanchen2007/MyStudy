### 解题思路
效率一般，还是桶排序快一些

### 代码

```python3
class Solution:
    def customSortString(self, S: str, T: str) -> str:  
        d = {}
        for i in range(97,123):
            d[chr(i)] = 26
        for i,char in enumerate(S):
            d[char] = i
        return ''.join(sorted(T,key=lambda x:d[x]))
```