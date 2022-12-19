in 在列表里面搜索是O(n)复杂度，但在集合里是O(1)，这几乎就是ms变ns级别的变化！
![捕获.PNG](https://pic.leetcode-cn.com/d64c0a38b8fe44ab6ee1028a6d6d3f733fdda693b88d1d2e63fc1b6ffadc298e-%E6%8D%95%E8%8E%B7.PNG)
```
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums = set(nums) #集合的好处在此，此处是列表就会超时，O(n)和O(n**2)
        if len(nums) <= 1:
            return []
        for i in nums:
            if target - i in nums:
                return [i, target - i]
        return []
```

