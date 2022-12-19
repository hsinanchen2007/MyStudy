### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isUnique(self, astr: str) -> bool:
        return True if len(astr)==len(set(astr)) else False
```