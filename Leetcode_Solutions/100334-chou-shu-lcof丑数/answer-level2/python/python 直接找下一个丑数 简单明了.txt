

```
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        ugly_nums = [1]
        if n<2:
            return ugly_nums[n-1]
        (start2,start3,start5) = (0,0,0)
        while len(ugly_nums)<n:
            (start2,start3,start5) = self.get_next(ugly_nums, start2,start3,start5)
        return ugly_nums[n-1]
    def get_next(self, ugly_nums: List[int], start2,start3,start5):
        ugly_nums.append(min(ugly_nums[start2]*2,ugly_nums[start3]*3,ugly_nums[start5]*5))
        if ugly_nums[-1]==ugly_nums[start2]*2: start2+=1
        if ugly_nums[-1]==ugly_nums[start3]*3: start3+=1
        if ugly_nums[-1]==ugly_nums[start5]*5: start5+=1
        return (start2,start3,start5)
```
