```
class Solution:
    def cuttingRope(self, n: int) -> int:
        self.result = [0, 1, 1]    # 存放最短长度
        if n<= 0:   return 0
        if n<= 2:   return self.result[n]
        self.dfs(n)
        return self.result[-1]

    def dfs(self, n: int):
        if n < len(self.result):
            return self.result[n]
        res = 0
        for i in range(1, n):
            tmp_res = max(self.dfs(i), i) * max(self.dfs(n-i), n-i)
            res = max(res, tmp_res)
        self.result.append(res)
        return res

```
