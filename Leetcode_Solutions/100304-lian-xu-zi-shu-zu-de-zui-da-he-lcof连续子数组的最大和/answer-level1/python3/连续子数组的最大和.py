### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # 作者：z1m
        res = nums[0]
        for i in range(1,len(nums)):
            if nums[i - 1] > 0:
                nums[i] += nums[i - 1]
            res = max(res, nums[i])
        return res

        # 作者：jyd
        # for i in range(1, len(nums)):
        #     nums[i] += max(nums[i - 1], 0)
        # return max(nums)



```