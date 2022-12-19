### 解题思路
看到题目只有一个思路，深搜。
一提交果然超时，加入记忆化即可。

### 代码

```python3
class Solution:
    def canCross(self, stones: List[int]) -> bool:
        self.target = stones[-1]
        stones = set(stones)
        return self.dfs(stones, 0, 0, {})

    def dfs(self, stones, cur, k, memo):
        if cur == self.target:
            return True
        if (cur, k) in memo:
            return memo[(cur, k)]
        for nxt in [k-1, k, k+1]:
            if nxt > 0 and cur + nxt in stones:
                if self.dfs(stones, cur+nxt, nxt, memo):
                    memo[(cur, k)] = True
                    return True
        memo[(cur, k)] = False
        return False
```