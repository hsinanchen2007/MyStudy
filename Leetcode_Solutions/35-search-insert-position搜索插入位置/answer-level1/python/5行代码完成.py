### 解题思路
一共两种情况，target在nums里、target不在nums里。
先来看在nums里的情况：从i=0开始找，如果nums[i]==target，返回i
再来看不在nums的情况：如果不在，就需要将target将插入的位置坐标返回，题目没有要求做插入操作，我就没写。由于是升序数组，那么target插入的位置前面都是小于它的，后面都是大于它的。我们从前往后找，一但找到nums[i]>target，就把target查到i这个位置，返回i。因为再往后插，就会有大于target的元素在它的前面了，就矛盾了。
基于上述分析，无论哪种情况都是返回i。所以可以合并成一句if nums[i]>=target:return i 
特殊情况：如果nums中所有元素都小于target，就插到最后。此时，i已经跳出了while循环，也就是说，i==len(nums)，直接返回i

### 代码

```python
class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        i=0
        while i<len(nums):
            if nums[i]>=target:return i                        
            i+=1
        return i 
        
```