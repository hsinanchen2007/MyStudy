class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        memo = []
        for _ in range(n):
            memo.append(1)
        for i in range(1, m):
            for j in range(1, n):
                memo[j] += memo[j-1]
        return memo[n-1]