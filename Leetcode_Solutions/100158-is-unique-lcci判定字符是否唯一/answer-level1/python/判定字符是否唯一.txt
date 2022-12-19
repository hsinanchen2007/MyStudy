### 解题思路
是否需要判断astr是否为空？

### 代码

```python3
class Solution:
    def isUnique(self, astr: str) -> bool:
        dic = collections.Counter(astr)
        for key,value in dic.items():
            if value > 1:
                return False
        
        return True
```