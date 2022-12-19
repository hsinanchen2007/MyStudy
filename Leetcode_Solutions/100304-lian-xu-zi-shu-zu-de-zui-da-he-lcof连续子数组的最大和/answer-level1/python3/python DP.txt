### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        '''
        for i in range(len(nums)):
            nums[i]+=nums[i-1]>0 and nums[i-1]
        return max(nums)
        '''

        maxnum=nums[0]
        for i in range(1,len(nums)):
            if nums[i-1]>0:
                nums[i]+=nums[i-1]
            maxnum = max(maxnum,nums[i])
        return maxnum
```