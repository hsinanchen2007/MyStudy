class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        satisfaction.sort()
        b = -1
        for i in range(len(satisfaction)):
            if satisfaction[i] >= 0:
                b = i
                break
        if b == -1:
            return 0
        dp =[0] * (b + 1)
        dp[0] = sum([(i + 1) * satisfaction[i] for i in range(len(satisfaction))])
        print(dp[0])
        for i in range(1, b + 1):
            dp[i] = dp[i - 1] - sum(satisfaction[i - 1:])
        print(dp)
        return max(dp)