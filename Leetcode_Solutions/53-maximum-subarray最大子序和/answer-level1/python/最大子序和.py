### 解题思路1：动态规划
* dp[i]代表什么? i位置的最大子序和
* 递归公式dp[i]=max(dp[i-1]+nums[i], nums[i])
* 初始化dp[0]=nums[0]
* 优化，只用到了dp中的一个，所以只是用一个o（1）的变量即可

### 代码

```python
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = nums[0]
        max_ = dp
        for i in range(1, len(nums)):
            dp = max(dp+nums[i], nums[i])
            if dp > max_:
                max_ = dp
        
        return max_
```

### 解题思路2：分治
* 思考子数组的位置，分为左边，右边和中间

### 代码
```python
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 分为子数组在middle左边，右边，和中间三种情况
        if len(nums) == 1:
            return nums[0]
        middle = len(nums)//2
        max_left = self.maxSubArray(nums[0:middle])
        max_right = self.maxSubArray(nums[middle:len(nums)])
        # 从middle开始往左边找最大
        i = middle-1
        max_middle_l = -float('inf')
        sum_l = 0
        while i >= 0:
            sum_l = sum_l+nums[i]
            max_middle_l = max(max_middle_l, sum_l)
            i -= 1
        # 从middle开始往右边找最大
        j = middle
        if not j < len(nums):
            max_middle_r = 0
        else:
            max_middle_r = -float('inf')
        sum_r = 0
        while j<len(nums):
            sum_r += nums[j]
            max_middle_r = max(max_middle_r, sum_r)
            j+= 1
        return max(max_left, max_right, max_middle_l+max_middle_r)
```