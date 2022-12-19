因为题目说众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素，所以排序后中间的数就是众数
```
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()
        l = len(nums)
        if l % 2 == 0:
            return nums[l // 2]
        else:
            return nums[l // 2]
```

