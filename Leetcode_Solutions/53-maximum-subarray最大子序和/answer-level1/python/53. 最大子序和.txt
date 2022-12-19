- 第二段代码是最好的, 其实思路都是一样的。


1. 动态规划思路1
- 思想是: 连续的子序列, 只需要对保留的上一个状态 和 当前的状态进行对比, 谁大谁是下一个(保留的上一个状态)
```
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 前一个值 或 前一组连续的值
        tmp = nums[0]
        max_ = tmp
        for i in range(1, len(nums)):
            # 前一组连续的值 强强联手 > 目前值 说明可以继续走下去了
            if tmp + nums[i] > nums[i]:
                max_ = max(tmp + nums[i], max_)
                tmp += nums[i]
            # 当前值 因为局部已经是小的情况了
            else:
                max_ = max(tmp, nums[i], max_)
                tmp = nums[i]
        return max_

print Solution().maxSubArray([-2,1,-3,4,-1,2,1,-5,4])
```

2. 动态规划思路2
- best 执行用时 :60 ms, 在所有 Python 提交中击败了92.59%的用户
- 思想是: 连续的子序列, 只需要对保留的上一个状态 和 当前的状态进行对比, 谁大谁是下一个(保留的上一个状态)
- 最后只需要max(当前数据)
```
class Solution(object):
    def maxSubArray(self, nums):
        for i in range(1, len(nums)):
            nums[i] = max(nums[i], nums[i] + nums[i-1])
        return max(nums)
```


