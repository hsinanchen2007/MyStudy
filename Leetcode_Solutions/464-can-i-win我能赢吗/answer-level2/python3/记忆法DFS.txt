## 思路:

动态规划

1. `maxChoosableInteger `大于等于`desiredTotal`，返回`true`；
2. 总和都没有`desiredTotal`大，肯定`false`
3. 状态压缩记录那些数被用过，带记忆化DFS

## 代码:

```python
class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        import functools
        if  desiredTotal <= maxChoosableInteger: return True
        if sum(range(maxChoosableInteger + 1)) < desiredTotal: return False
        
        @functools.lru_cache(None)
        def dfs(used, desiredTotal):
            for i in range(maxChoosableInteger):
                cur = 1 << i
                if cur & used == 0:
                    if desiredTotal <= i + 1 or not dfs(cur | used, desiredTotal - i - 1):
                        return True
            return False
        
        return dfs(0, desiredTotal)
        
```

