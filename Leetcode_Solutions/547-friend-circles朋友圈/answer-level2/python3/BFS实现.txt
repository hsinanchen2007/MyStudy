[DFS实现](https://leetcode-cn.com/problems/friend-circles/solution/dfs-by-matrix95/)
以下是BFS实现：
```
class Solution:
    def findCircleNum(self, M):

        queen = []
        visited = set()
        ans = 0

        # 实现广度优先遍历
        def bfs(i):
            queen.append(i)
            while queen:
                i = queen[0]
                queen.pop(0)  # 这是一个左进右出的队列
                for j in range(len(M[i])):
                    if M[i][j] and j not in visited:
                        visited.add(j)
                        queen.append(j)

        for i in range(len(M)):
            if i not in visited:
                bfs(i)
                ans += 1
        return ans

```
