求出不缺失数字的和，再依次减去列表中的数，即可得出缺失值。
```
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        t=n*(n+1)/2
        for num in nums:
            t-=num
        return int(t)
```
