同样都是DP的思想，用下面这段代码可以在20ms左右通过测试，目前看来是100%, 不知道为什么这么写很快。若哪位大佬了解具体原因，求解惑。

```
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_sum   = nums[0]
        pre     = nums[0]

        for i in range(1, len(nums)):
            if pre >=0:
                pre = pre + nums[i]            
            else:
                pre = nums[i]
    
            if max_sum <= pre:
                max_sum = pre
        return max_sum
```
