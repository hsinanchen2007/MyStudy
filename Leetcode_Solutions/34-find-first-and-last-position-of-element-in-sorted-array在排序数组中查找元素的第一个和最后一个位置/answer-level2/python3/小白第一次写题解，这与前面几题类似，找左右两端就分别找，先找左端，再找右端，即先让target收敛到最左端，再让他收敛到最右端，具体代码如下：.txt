```
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if len(nums)==0:  #当为空的情况
            return [-1,-1]
        l,r=0,len(nums)-1
        l1,r1=0,len(nums)-1
        while l<r:    #让target收敛到左边，即最后会收敛到target=nums[left],返回left即可，可以就举例两个数字来试试
            mid=(l+r+1)//2   #mid靠右，left=mid，最后剩两个的时候mid会收敛到left
            if nums[mid-1]>=target:  #！！！target要在左边要取等，因为mid-1也在左边，所以要取等
                r=mid-1
            else:
                l=mid
        # print(l)
        while l1<r1:
            mid2=(l1+r1)//2
            if target>=nums[mid2+1]:  #！！！这里取等，因为mid2+1也在右边
                l1=mid2+1
            else:
                r1=mid2
        # print(r1)
        return [l,r1] if nums[l]==target else [-1,-1]

```

