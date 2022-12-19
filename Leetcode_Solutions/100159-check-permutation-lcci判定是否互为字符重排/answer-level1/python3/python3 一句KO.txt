### 解题思路
直接排序比较即可，python一句搞定

### 代码

```python3
class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        return(sorted(s1)==sorted(s2))
```