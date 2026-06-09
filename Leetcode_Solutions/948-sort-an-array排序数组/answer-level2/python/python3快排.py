### 解题思路
快排

### 代码

```python3
class Solution:
    def sortArray(self, nums):
        return self.quickSort(nums)


    def quickSort(self,nums):
        
        if(len(nums)==0):
            return []
        if(len(nums)==1):
            return nums
        flag = nums[0]
        left=[]
        right=[]
        for i in range(1,len(nums)):
            if nums[i]>flag:
                right.append(nums[i])
            else:
                 left.append(nums[i])
        left = self.quickSort(left) 
        right = self.quickSort(right)
        
        return left+[flag]+right            



```