```
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # 将序列变成集合，以免重复遍历。
        set_nums = set(nums)
        for item in set_nums:
            if nums.count(item)>(len(nums)//2):
                return item
```
