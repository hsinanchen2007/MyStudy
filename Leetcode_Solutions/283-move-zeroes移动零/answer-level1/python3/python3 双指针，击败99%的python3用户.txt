### 解题思路
在纸上把移动过程模拟一边就ok

### 代码



```
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        i = 0
        j = 1

        while(i<j and j<len(nums)):
            if nums[i]==0 and nums[j]!=0:
                nums[i],nums[j] = nums[j],nums[i]
            elif nums[i]==0 and nums[j]==0:
                j+=1
            else:
                i+=1
                j+=1
```
