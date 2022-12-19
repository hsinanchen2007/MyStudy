### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        
        maxCount = nums[0]
        count = nums[0]
        for i in range(1, len(nums)):
            if nums[i] < 0:
                count = nums[i] if nums[i] + count <= 0 else count + nums[i]
            elif nums[i] >= 0:
                count = count + nums[i] if count > 0 else nums[i]
            if count > maxCount:
                maxCount = count
        return maxCount
                
        
        

                        

                

```