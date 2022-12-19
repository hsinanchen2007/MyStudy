
```python
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        #三指针，把0往前放，2最后放，1不管
        #index 用于保存先前的1的位置，等找到0时候再2把0换过来
        index=0
        #当左指针为0，把先前的1换掉；当左指针为2时，放到最右边去，然后右指针往左走，继续判断，直至满足条件。
        l=0
        r=len(nums)-1
        while l<=r:
            if nums[l]==0:
                nums[l],nums[index]=nums[index],nums[l]
                index+=1
                l+=1
            elif nums[l]==2:
                nums[l],nums[r]=nums[r],nums[l]
                r-=1
            else:
                l+=1
        return nums