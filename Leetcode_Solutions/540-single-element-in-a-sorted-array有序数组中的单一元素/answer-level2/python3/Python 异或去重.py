应用异或操作的性质：a^b^a=b可以去除数组中成对出现的元素，最后剩下的即为所求
```
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        ans = nums[0]
        for i in range(1,len(nums)):
            ans = ans^nums[i]
        return ans
```
