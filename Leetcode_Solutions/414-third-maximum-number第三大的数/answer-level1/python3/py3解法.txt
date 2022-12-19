```
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        size = len(nums)
        n1,n2,n3=2-sys.maxsize,1-sys.maxsize,-sys.maxsize
        for i in range(len(nums)):
            n = nums[i]
            if n>n1:
                n1,n2,n3=n,n1,n2
            elif n>n2 and n<n1:
                n1,n2,n3=n1,n,n2
            elif n>n3 and n<n2:
                n1,n2,n3=n1,n2,n
        if size < 3 or n3<=3-sys.maxsize:
            return n1
        return n3
```
