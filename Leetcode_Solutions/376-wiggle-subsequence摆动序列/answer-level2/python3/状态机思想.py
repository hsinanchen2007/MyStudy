### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        max_length = 1
        begin = 0
        up = 1
        down = 2
        staus = begin
        if len(nums) < 1:
            return 0
        if len(nums) < 2:
            return 1
        for i in range(1, len(nums)):

            if staus == 0:
                if nums[i-1] == nums[i]:
                    staus = begin
                elif nums[i-1] < nums[i]:
                    staus = up
                    max_length += 1
                elif nums[i-1] > nums[i]:
                    staus = down
                    max_length += 1
            elif staus == 1:
                if nums[i-1] <= nums[i]:
                    staus = up
                else:
                    staus = down
                    max_length += 1
            elif staus == 2:
                if nums[i-1] >= nums[i]:
                    staus = down
                else:
                    staus = up
                    max_length += 1
        
        return max_length
            

```