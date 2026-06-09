### 解题思路
映射map

### 代码

```python3
class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        str=str.split()
        return tuple(map(pattern.index,pattern))==tuple(map(str.index,str))
```