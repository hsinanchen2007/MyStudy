### 解题思路
第一次从后遍历，找到非递增点i，若无则对nums排序
若找到，则继续从后遍历找到比nums[i]大的位置，进行交换，然后从i+1位置将以后元素reversed

### 代码

```python3
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i=len(nums)-2
        while i>=0 and nums[i]>=nums[i+1]:
            i-=1
        if i<0:nums.sort()
        else:
            j=len(nums)-1
            while nums[i]>=nums[j] and j>i:
                j-=1
            nums[i],nums[j]=nums[j],nums[i]
            nums[i+1:]=reversed(nums[i+1:])

            
        

```