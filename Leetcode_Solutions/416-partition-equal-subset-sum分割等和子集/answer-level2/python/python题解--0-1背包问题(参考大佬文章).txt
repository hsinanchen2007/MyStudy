### 解题思路
- 这里我只给出python的代码,具体的讲解参考大神的解释,非常受教
- [https://leetcode-cn.com/problems/partition-equal-subset-sum/solution/0-1-bei-bao-wen-ti-xiang-jie-zhen-dui-ben-ti-de-yo/]()

### 代码

```python
class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        sum_ = sum(nums)
        if sum_ & 1:
            return False
        target = sum_ / 2

        dp = [False]*(target+1)

        if nums[0] <= target:
            dp[nums[0]] = True
        dp[0] = True
        
        for i in range(1,len(nums)):
            for j in reversed(range(nums[i],target+1)):
                dp[j] = dp[j] or dp[j-nums[i]]
            if dp[-1]:
                return True
        return dp[-1]

```