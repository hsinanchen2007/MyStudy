### 解题思路
把非0的都挪到前面去，剩下的位置全部赋值为0

### 代码

```python
class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        p1=0
        p2=0
        while p1<len(nums):
            if nums[p1]!=0:
                nums[p2]=nums[p1]
                p2+=1
                p1+=1
            else:
                p1+=1
        while p2<len(nums):
            nums[p2]=0
            p2+=1
        return nums
```