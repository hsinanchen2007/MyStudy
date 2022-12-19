### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def searchRange(self, nums, target):
        l=0
        h=len(nums)-1

        while l<=h:
            if l==h:
                if nums[l]!=target:
                    return [-1,-1]
            m=l+(h-l)/2
            if nums[m]==target:
                l,h=m,m
                while(l>=0):
                    if nums[l]==target:
                        if l>=1:
                            l=l-1
                            signal_l=1
                        else:
                            break
                    elif nums[l]!=target:
                        if signal_l==1:
                            l+=1
                        break
                while(h<len(nums)):
                    if nums[h]==target:
                        if h<len(nums)-1:
                            h=h+1
                            signal_h=1
                        else:
                            break
                    else:
                        if signal_h==1:
                            h-=1
                        break
                return [l,h]
            elif nums[m]>target:
                h=m
            elif nums[m]<target:
                l=m+1
        return [-1,-1]
```