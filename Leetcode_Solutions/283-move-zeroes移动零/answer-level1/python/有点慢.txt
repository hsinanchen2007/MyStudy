### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l, r = 0, len(nums) - 1
        while l <= r:
            if nums[l] != 0:
                l += 1
            else:
                tmp = nums[l]
                nums.remove(tmp)
                nums.insert(r, tmp)
                r -= 1
        return nums
```