
执行用时 :48 ms, 在所有 Python3 提交中击败了97.07%的用户
内存消耗 :14.6 MB, 在所有 Python3 提交中击败了91.95%的用户
```python [3]
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return
        if len(nums) == 1:
            return nums[0]
        if len(nums) ==2:
            return
        val_in_nums = nums[0]
        for i in range(1,len(nums)):
            val_in_nums = val_in_nums ^ nums[i]
        return val_in_nums
            
```
