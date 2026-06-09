
def findNumberOfLIS(nums):
        ## 求最长上升子序列
        n = len(nums)
        if n < 2:
            return n
        
        dp = [1 for i in range(n)]
        count = [0 for i in range(n)]  # 记录目前最长子序列个数
        count[0] = 1

        for i in range(1, n):
            for j in range(i):
                if nums[j] < nums[i]:
                    if dp[j] + 1 > dp[i]:  
                        dp[i] = dp[j] + 1
                        count[i] = 1 * count[j]  # 长度更新，计数更新
                    elif dp[j] + 1 == dp[i]:
                        count[i] += 1 * count[j] # 长度重复，则计数累加
                    else:
                        pass
            if dp[i] == 1:
                count[i] = 1
        
        max_len = max(dp)
        res = 0
        for i in range(len(dp)):
            if dp[i] == max_len:
                res += count[i]
        return res