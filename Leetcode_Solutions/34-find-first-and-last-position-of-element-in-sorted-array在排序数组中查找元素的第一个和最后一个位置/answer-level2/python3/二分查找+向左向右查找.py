### 解题思路
二分查找，找到后，然后向左向右进行查找，然后返回index

### 代码

```python3
class Solution:
    def searchRange(self, nums, target: int):
        def b_search(list_nums,frist,end,target1):
            if frist>end:
                return -1
            f=frist
            e=end
            mid=(frist+end)//2
            if nums[mid]>target1:
                return  b_search(list_nums,f,mid-1,target1)
            elif nums[mid]<target1:
                return  b_search(list_nums,mid+1,e,target1)
            else:
                return mid

        index=b_search(nums,0,len(nums)-1,target)
        print(index)
        if index==-1:
            return [-1,-1]
        index1=index
        index2=index
        res=[]
        while nums[index1]==target and index1>0:
            index1=index1-1
        if nums[index1]==target:
            res.append(index1)
        else:
            res.append(index1+1)
        while nums[index2]==target and index2<len(nums)-1:
            index2=index2+1
        if nums[index2]==target:
            res.append(index2)
        else:
            res.append(index2-1)
        return res
        




```