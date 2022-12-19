### 解题思路
通过集合去重，再对比长度

### 代码

```python3
class Solution:
    def isUnique(self, astr: str) -> bool:
        if len(astr) == len(set(list(astr))):
            return True
        else:
            return False
        

```