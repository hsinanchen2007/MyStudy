```
def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if not nums:
            return nums
        # 先排序
        nums.sort()
        # 备忘录：除数个数+除数元素(方便输出)
        dp = [1 for i in range(len(nums))]
        divisors = [[] for i in range(len(nums))]
        # 遍历，更新
        for i in range(len(nums)):
            for j in range(0, i):
                if nums[i] % nums[j] == 0:
                    # 状态转移
                    if dp[j] + 1 > dp[i]:
                        dp[i] = dp[j] + 1
                        divisors[i].append(nums[j])
            # 可被自己整除
            divisors[i].append(nums[i])
        # 找出有最多除数的元素，输出保存的除数集合
        index = dp.index(max(dp))
        return divisors[index]


```
