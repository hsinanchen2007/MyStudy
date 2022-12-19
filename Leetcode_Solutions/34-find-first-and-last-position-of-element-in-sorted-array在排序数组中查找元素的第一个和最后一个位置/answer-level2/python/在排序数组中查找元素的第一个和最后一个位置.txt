### 解题思路
从前往后和从后往前

### 代码

```python3
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        # if len(nums) == 1 and nums[0] == target:
        #     return [0,0]

        pos = []
        for num in nums:
            if num == target:
                pos.append(nums.index(num))
                break
        
        for i in range(len(nums) - 1, -1, -1):
            if nums[i] == target:
                pos.append(i)
                break
        
        if len(pos) == 0:
            return [-1,-1]
        else:
            return pos


```