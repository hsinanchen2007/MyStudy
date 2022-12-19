## 模拟法

简单题目。 直接根据题目描述模拟游戏规则即可， 没什么技术含量。

## 思路


```python
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        self.ans = 0
        def dfs(i, j, dx, dy):
            if i < 0 or i >= 8 or j < 0 or j >= 8: return
            if board[i][j] == 'B': return
            if board[i][j] == 'p':
                self.ans += 1
                return
            dfs(i + dx, j + dy, dx, dy)

        for i in range(8):
            for j in range(8):
                if board[i][j] == 'R':
                    dfs(i + 1, j, 1, 0)
                    dfs(i - 1, j, -1, 0)
                    dfs(i, j + 1, 0, 1)
                    dfs(i, j - 1, 0, -1)
        return self.ans
```

由于题目数据量大小是固定的，因此无法分析复杂度。

更多题解可以访问我的LeetCode题解仓库：https://github.com/azl397985856/leetcode  。 目前已经接近30K star啦。

大家也可以关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab900392e328c2670cddc-file_1581478989502)
