class Solution:
    '''
    感谢力扣官方提供思路：
    记忆化深度搜索
    '''
    def __init__(self):
        self.m, self.n = 0, 0
        self.d = ((0, 1), (1, 0), (0, -1), (-1, 0))
        self.flag = []

    def longestIncreasingPath(self, matrix) -> int:
        if not matrix: return 0
        self.m, self.n = len(matrix), len(matrix[0])
        self.flag = [[0 for _ in range(self.n)] for _ in range(self.m)]
        return_max = 0
        for i in range(self.m):
            for j in range(self.n):
                return_max = max(return_max, self.dfs(matrix, i, j))
        return return_max

    def dfs(self, matrix, i, j):
        if self.flag[i][j] != 0: return self.flag[i][j]
        for (x, y) in self.d:
            x, y = i + x, j + y
            if 0 <= x and x < self.m and 0 <= y and y < self.n and matrix[x][y] > matrix[i][j]:
                self.flag[i][j] = max(self.flag[i][j], self.dfs(matrix, x, y))
        self.flag[i][j] += 1
        return self.flag[i][j]