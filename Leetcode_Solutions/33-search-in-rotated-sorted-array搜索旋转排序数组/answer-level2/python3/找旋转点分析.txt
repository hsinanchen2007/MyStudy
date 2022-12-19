### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:

        def binary_search(nums,target,start,end):
            if start>end:return
            mid=int((start+end)/2)
            if nums[mid]==target:
                self.res=mid
            if nums[0]>nums[-1]:
                if target<nums[mid]:
                    if nums[0]>nums[mid]:
                        binary_search(nums,target,start,mid-1)
                    elif nums[0]<nums[mid]:
                        if target>=nums[0]:
                            binary_search(nums,target,start,mid-1)
                        elif target<nums[0]:
                            binary_search(nums,target,mid+1,end)
                    else:binary_search(nums,target,mid+1,end)
                if target>nums[mid]:
                    if nums[0]>nums[mid]:
                        if target>=nums[0]:
                            binary_search(nums,target,start,mid-1)
                        else:
                            binary_search(nums,target,mid+1,end)
                    elif nums[0]<nums[mid]:
                        binary_search(nums,target,mid+1,end)
                    else:binary_search(nums,target,mid+1,end)
            else:
                if target>nums[mid]:
                    binary_search(nums,target,mid+1,end)
                if target<nums[mid]:
                    binary_search(nums,target,start,mid-1)

        self.res=-1
        binary_search(nums,target,0,len(nums)-1)
        return self.res










        # def binary_search(nums,target,start,end):
        #     if start>end:return
        #     mid=int((start+end)/2)
        #     if nums[mid]==target:
        #         self.res=mid
        #     binary_search(nums,target,mid+1,end)
        #     binary_search(nums,target,start,mid-1)

        # self.res=-1
        # binary_search(nums,target,0,len(nums)-1)
        # return self.res
```