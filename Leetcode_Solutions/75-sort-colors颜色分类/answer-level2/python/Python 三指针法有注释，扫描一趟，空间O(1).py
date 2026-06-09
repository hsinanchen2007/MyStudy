### 解题思路
思路与官方提供的三指针是一样的，这里给出Python版代码。

### 代码

```python
class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        lenn=len(nums)
        if lenn<=1:return
        i,j=0,lenn-1
        k=0
        while i<j and k>=i and k<=j:
            while i<j and nums[i]==0:i+=1       #之所以用while，是为了方便理解，即“找到第一个不满足这个条件的数”
            while i<j and nums[j]==2:j-=1       #同上
            k=i
            while k<=j and nums[k]==1:k+=1      #同上
            if k>j:return                       #当上一行遇到全部元素已经归位的情况，k会超过j，这时候就可以直接退出了
            if nums[k]==0:
                nums[i],nums[k]=nums[k],nums[i] #交换这两个元素
            elif nums[k]==2:
                nums[j],nums[k]=nums[k],nums[j]        
```