295 / 313 个通过测试用例，虽然还是超时了，但可以先sort来解决重复答案问题，O(n^3)。

```python []
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # solution1 : Brute Force, O(n^3)
        res = []
        nums.sort() # sort 以后[nums[i], nums[j], nums[k]]就是有序的为以后判重方便
        for i in range(len(nums) - 2):
            for j in range(i + 1, len(nums) - 1):
                for k in range(j + 1, len(nums)):
                    if nums[k] + nums[i]+ nums[j] == 0 and [nums[i], nums[j], nums[k]] not in res:
                        res.append([nums[i],nums[j], nums[k]])
        return res
```

