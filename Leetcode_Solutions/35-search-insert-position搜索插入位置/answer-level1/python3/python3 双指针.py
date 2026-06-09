### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        find_pos = False
        i = 0
        j = len(nums) - 1
        while not find_pos:
            if nums[i] < target < nums[j]:
                i += 1
                j -= 1
            elif nums[i] == target:
                find_pos = True
                return i 
            elif nums[j] == target:
                find_pos = True
                return j
            elif target < nums[i]:
                find_pos = True
                return i
            elif target > nums [j]:
                find_pos = True
                return j + 1
            
```