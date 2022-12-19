### 解题思路
此处撰写解题思路
如题，本题是searching问题，所以想到用binary search算法来降低时间复杂度。

dig a little deeper: 
与binary search不同的有两点，一是返回值是index，二是必须返回一个有效index。

根据examples, 可以推导出当middle不满足条件时，firstIndex可以直接满足条件。

题解完成。

### 代码

```python
class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        first = 0  # first index
        last = len(nums) - 1  # last index

        while first <= last:  # search current indices of list
            middle = (first + last)//2  # comparing index
            if nums[middle] == target:  # comparing
                return middle   # match, return index
            else:   # change the range of indices
                if nums[middle] > target:  # comparing 
                    last = middle - 1
                else:
                    first = middle + 1
        
        return first
```