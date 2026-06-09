### 解题思路
双指针法

### 代码

```python3
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        left = 0
        right = len(nums) - 1
        if right<=0:
            return nums
        while left!=right:
            if nums[right]%2==0:
                right = right - 1
                continue
            elif nums[left]%2==1:
                left = left + 1
                continue
            else:
                swap = nums[left]
                nums[left] = nums[right]
                nums[right] = swap    
        return nums
            
```