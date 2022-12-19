排序，检索range(n),比较nums[i]和nums[i+1]，重复的数字nums[i]和nums[i+1]相同
执行用时 :60 ms, 在所有 Python3 提交中击败了75.11%的用户
内存消耗 :14.3 MB, 在所有 Python3 提交中击败了98.29%的用户
```python []
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort() 
        for i in range(n):
            if nums[i] == nums[i+1]:
                return nums[i]
```

