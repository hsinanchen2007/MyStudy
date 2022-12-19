```
class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if matrix == []:
            return []
        m = len(matrix)
        n = len(matrix[0])
        res = []
        self.visited = set()

        def dfs(x, y):
            dx = [0, 1, 0, -1]
            dy = [1, 0, -1, 0]

            if 0 <= x < m and 0 <= y < n and (x, y) not in self.visited: # 向上需要改变旋转顺序
                res.append(matrix[x][y])
                self.visited.add((x, y))
                for k in range(4):
                    if y == 0 or (x, y - 1) in self.visited:
                        dfs(x + dx[(k + 3) % 4], y + dy[(k + 3) % 4])
                    else:
                        dfs(x + dx[k], y + dy[k])

        for i in range(m):
            for j in range(n):
                dfs(i, j)
        return res
```
