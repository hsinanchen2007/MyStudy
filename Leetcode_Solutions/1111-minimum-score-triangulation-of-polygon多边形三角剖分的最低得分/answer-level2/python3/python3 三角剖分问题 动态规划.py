class Solution(object):
    def minScoreTriangulation(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        len_a = len(A)
        min_score = float('inf')
        dp = [[float('inf')]*len_a for _ in range(len_a)]

        for i in range(0, len_a-1):
            dp[i][i+1] = 0   # 因为下面公式中 + 了  a[i] * a[k] * a[j]  所以边界条件下，就是应该 dp[i][k] 与 dp[k][j] == 0

        for d in range(2, len_a): # 方法 在想边界的时候，可以将边界带入 然后看是否符合含义  比如此时边界值是len_a - 1 然后带入发现 i只有一个选项是0  j的选项是len_a - 1
            for i in range(0, len_a-d):
                j = d + i 
                for k in range(i+1, j):
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[i]*A[k]*A[j])
        return dp[0][len_a-1]