class Solution(object):
    def numEnclaves(self, A):
        """
        :type A: List[List[int]]
        :rtype: int
        """
        if not A:
            return 0
        direction = [(-1, 0), (0, -1), (1, 0), (0, 1)]
        def dfs(i, j):
            A[i][j] = 0
            for x, y in direction:
                if 0 <= i + x < len(A) and 0 <= j + y < len(A[0]) and A[i + x][j + y] == 1:
                    dfs(i + x, j + y)
        for i in range(len(A)):
            if A[i][0] == 1:
                dfs(i, 0)
            if A[i][len(A[0]) - 1] == 1:
                dfs(i, len(A[0]) - 1)
        for i in range(len(A[0])):
            if A[0][i] == 1:
                dfs(0, i)
            if A[len(A) - 1][i] == 1:
                dfs(len(A) - 1, i)
        res = 0
        for i in range(len(A)):
            for j in range(len(A[0])):
                if A[i][j] == 1:
                    res += 1
        return res
                    