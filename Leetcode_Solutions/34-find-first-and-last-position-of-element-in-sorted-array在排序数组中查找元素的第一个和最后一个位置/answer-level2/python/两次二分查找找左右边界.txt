### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
#解法一，两个二分查找分别找target左右端点，用时超96%
        def left_bound(nums,target,start,end):
            if start>end:return 
            mid=int((start+end)/2)
            if target==nums[mid]:
                if mid==0 or nums[mid-1]!=target:
                    self.ans[0]=mid
                left_bound(nums,target,start,mid-1)

            if target>nums[mid]:
                left_bound(nums,target,mid+1,end)
            if target<nums[mid]:
                left_bound(nums,target,start,mid-1)
        def right_bound(nums,target,start,end):
            if start>end:return 
            mid=int((start+end)/2)
            if target==nums[mid]:
                if mid==len(nums)-1 or nums[mid+1]!=target:
                    self.ans[1]=mid
                right_bound(nums,target,mid+1,end)
            if target>nums[mid]:
                right_bound(nums,target,mid+1,end)
            if target<nums[mid]:
                right_bound(nums,target,start,mid-1)

        self.ans=[-1,-1]
        left_bound(nums,target,0,len(nums)-1)
        right_bound(nums,target,0,len(nums)-1)
        return self.ans






        # def traceback(nums,target,start,end):
        #     if start>end:return 
        #     mid=int((start+end)/2)
        #     if target==nums[mid]:
        #         self.ans=[mid,mid]
        #         #print(self.ans)
        #         for i in range(mid+1,len(nums)):
        #             if nums[i]==target:self.ans[1]+=1
        #             else:break
        #         for i in range(mid-1,-1,-1):
        #             if nums[i]==target:self.ans[0]-=1
        #             else:break

        #     if target>nums[mid]:
        #         traceback(nums,target,mid+1,end)
        #     if target<nums[mid]:
        #         traceback(nums,target,start,mid-1)

        
        # self.ans=[-1,-1]
        # traceback(nums,target,0,len(nums)-1)
        # return self.ans
```