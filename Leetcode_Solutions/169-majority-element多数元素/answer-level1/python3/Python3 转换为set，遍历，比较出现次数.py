set是集合，集合的特点是不包含重复元素。
```Python
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # 最小次数
        min_times = len(nums) / 2
        # 转换为集合
        set_nums = set(nums)
        # 遍历集合中的元素，计算在nums中出现的次数
        for i in set_nums:
            if nums.count(i) > min_times:
                return i
```
