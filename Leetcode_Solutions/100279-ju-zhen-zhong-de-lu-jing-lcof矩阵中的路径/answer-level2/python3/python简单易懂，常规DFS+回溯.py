### 解题思路
主程序寻找起点，辅助函数用于在给定起点和已探测节点的基础上继续DFS探测，同时用一个字典保留已探测的节点避免重复探测。
当探测节点个数等于目标字符串长度时，即可返回；否则回溯至上一节点。

### 代码

```python3
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def isValid(i, j):#判断坐标是否在范围合法
            return 0<=i<m and 0<=j<n

        def DFS(i, j, seen):#在当前(i, j)基础上继续探测，seen记录已探测节点
            if len(seen) >= len(word):
                return True
            for dx, dy in delt:
                x, y = i+dx, j+dy
                if isValid(x, y) and word[len(seen)] == board[x][y] and (x, y) not in seen:
                    seen[(x, y)] = 1#标记
                    if DFS(x, y, seen):
                        return True
                    seen.pop((x, y))#回溯
            return False

        m, n = len(board), len(board[0])
        delt = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        flags = [[0]*n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                seen = {}
                if board[i][j] == word[0]:#找到入口
                    seen[(i, j)] = 1
                    if DFS(i, j, seen):
                        return True
        return False
```
欢迎关注个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)