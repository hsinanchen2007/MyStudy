```
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        while(i != len(nums)):
            if nums[i] in nums[i+1:]:
                del nums[i]
            else: 
                i += 1
        return len(nums)
```

遍历列表，如果该目标元素在之后的列表中存在，那么就将该元素删除，直到没有重复元素为止。
缺点：时间复杂度O（n^2），运行速度没有双指针法快