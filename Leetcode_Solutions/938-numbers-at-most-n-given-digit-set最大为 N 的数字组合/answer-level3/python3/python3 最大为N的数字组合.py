class Solution(object):
    def atMostNGivenDigitSet(self, D, N):
        """
        :type D: List[str]
        :type N: int
        :rtype: int
        """
        N = str(N)
        len_n = len(N)
        dp = [0 for _ in range(len(N)+1)]  # d[0] = 241 d[1] = 41 d[2]=1 d[3]=1
        dp[len(N)] =  1  #终止条件是，如果j==N[i]的时候 刚好就一个数，所以从这里滚动过来 dp[len[N]] 为1
        for i in range(len_n - 1, -1, -1):
            sum_les = 0
            for j in D:
                if j < N[i]:
                    dp[i] += len(D)**(len_n - 1 -i)
                if j == N[i]:
                    dp[i] += dp[i+1]

        for i in range(1, len_n):
            dp[0] += len(D)**i
        return dp[0]
        