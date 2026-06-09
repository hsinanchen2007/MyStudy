### 解题思路
跟之前的数组去重几乎完全一样的解法
通过双指针交换0和后面的非0数
时间复杂度O(n)
空间复杂度O(1)
操作更少的思路暂时没有想到

### 代码

```python3
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l=r=0
        while r<len(nums):
            if nums[l]==0 and nums[r]!=0:nums[l],nums[r]=nums[r],nums[l]
            if nums[l]!=0:l+=1
            r+=1
```