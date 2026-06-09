先找到旋转点，再把数组分为两组，旋转点前的为一组，之后的为一组，根据target的值选择在哪组中用二分法查找
```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums:
            return -1
        l=0
        r=len(nums)-1
        while l<r:
            m=l+(r-l)//2
            if nums[m]>nums[r]:
                l=m+1
            else:
                r=m
        t=l
        if target==nums[t]:
            return t
        else:
            if target>nums[-1]:
                l = 0
                r = t-1
            else:
                l = t
                r = len(nums) - 1
            while l<=r:
                m=l+(r-l)//2
                if nums[m]>target:
                    r = m-1
                elif nums[m]<target:
                    l=m+1
                else:
                    return m
            return -1
```
