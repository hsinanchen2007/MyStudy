### 解题思路


### 代码

```python3
class Solution:
    def isUnique(self, astr: str) -> bool:
        return len(astr) == len(set(astr)) 
```