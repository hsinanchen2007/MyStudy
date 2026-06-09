取余数是1 和 2 的最小值和次小值
如果sum(nums)的余数是0，直接返回，是1的话，取 余数是1的最小 和余数是2的最小加次小的和 中小的那个，用总和减，余数是2相同
```
class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        r1=rr1=r2=rr2=float('inf')
        if sum(nums)%3==0: return sum(nums)
        for i in nums:
            if i%3==1:
                if i<=r1: r1, rr1 = i, r1
                elif r1<i<rr1: rr1 = i
            if i%3==2:
                if i<=r2: r2, rr2 = i, r2
                elif r2<i<rr2: rr2 = i
        return max(sum(nums)-r1, sum(nums)-r2-rr2) if sum(nums)%3==1 else max(sum(nums)-r2, sum(nums)-r1-rr1)
```
