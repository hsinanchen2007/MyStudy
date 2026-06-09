### 解题思路

![image.png](https://pic.leetcode-cn.com/a1750b0bd757d7531b6428cdfc23bd3c03ace90c7008bdfd5a5f623cf42afbcc-image.png)

### 代码

```python
class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left,right=0,len(nums)-1
        while left<right:
            mid = left+(right-left)//2
            if nums[mid]<=nums[right]:
                right=mid
            else:
                left=mid+1
        return nums[left]
```