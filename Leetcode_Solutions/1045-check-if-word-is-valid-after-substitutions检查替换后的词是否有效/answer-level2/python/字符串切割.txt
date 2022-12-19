### 解题思路
如果S中有abc就删除，最后为空就是有效的，不为空就无效

### 代码

```python3
class Solution:
    def isValid(self, S: str) -> bool:
        while 'abc' in S:
            S = S.replace('abc','')
        if len(S) == 0:
            return True
        else:
            return False
```