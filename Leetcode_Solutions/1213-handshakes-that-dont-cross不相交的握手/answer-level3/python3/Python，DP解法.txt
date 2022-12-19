简单的dp解法，比如8个节点的情况，对于每个初始节点1 而言， 它可以和2 4 6 8 连接，当和2 链接时，左边剩下0个节点，右边剩下6个节点，即此时解法数为dp[0]*dp[6] = 5；1和4链接时，左右剩下2 3 两个节点，右边剩下 4个节点，即此时解法数为dp[2]*dp[4] = 2；1和6连为dp[4]*dp[2] = 2； 1和8连为dp[6]*dp[0] = 5；即每一个问题都可以化为已经解决过的子问题，最终答案为14，代码如下：

`class Solution(object):
    def numberOfWays(self, num_people):
        """
        :type num_people: int
        :rtype: int
        """
        dp = [0] * (num_people + 1)
        dp[0] = 1
        dp[2] = 1

        for i in range(2, num_people // 2 + 1):
            for j in range(i):
                dp[i * 2] += dp[j * 2] * dp[i*2 - 2 - j * 2]

        return (dp[num_people] % (1000000000+7) )
`