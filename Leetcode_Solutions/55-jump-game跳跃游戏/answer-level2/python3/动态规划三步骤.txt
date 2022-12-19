```
    def canJump(self, nums):
        """
        1. dp[i]表示是否能到达位置i
        2. 关系：dp[i] = (dp[i-1] and nums[i-1]>=1) or (dp[i-2] and nums[i-2]>=2) or ....
        3. 初始值：dp[0] = true
        :param nums:
        :return:
        """
        dp = [True]
        def _dpfunc():
            for i in range(1, len(nums)):
                _can = False
                for j in range(i-1, -1, -1):
                    if dp[j] and nums[j] >= i-j:
                        _can = True
                        break
                dp.append(_can)
        _dpfunc()
        return dp[-1]
```
