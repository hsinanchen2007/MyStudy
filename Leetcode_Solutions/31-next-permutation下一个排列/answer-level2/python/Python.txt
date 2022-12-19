### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def nextPermutation(self, nums):
        def swap(a,b):
            tem=nums[a]
            nums[a]=nums[b]
            nums[b]=tem
        def paixu(t):
            for i in range(t,len(nums)-1):
                for j in range(len(nums)-1,i,-1):
                    if nums[j]<nums[j-1]:
                        swap(j,j-1)

        for i in range(len(nums)-1,0,-1):
            if nums[i]>nums[i-1]:
                temp_min = i
                for j in range(i,len(nums)):
                    if nums[j]<nums[temp_min] and nums[j]>nums[i-1]:
                        temp_min=j
                swap(temp_min,i-1)
                paixu(i)
                return nums
        return nums.sort()
```