```
class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        sum1 = sum(nums)
        n1 = len(nums)
        nums.sort()
        n2 = int(n1/2)
        middle_count = nums[n2]
        num = 0
        for i in nums:
            a1 = abs(middle_count - i)
            num += a1
        return(num)
```
