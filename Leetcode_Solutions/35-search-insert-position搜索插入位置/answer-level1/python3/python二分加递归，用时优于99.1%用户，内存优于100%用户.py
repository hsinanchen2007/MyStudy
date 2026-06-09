![leetcode.png](https://pic.leetcode-cn.com/4d45bc3595c7188acba71ea982bd7ff091d5c20490473a70d49e8e47b046a6cb-leetcode.png)

```
class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        middle = len(nums)//2
        
        if not middle:
            return middle+1 if target>nums[middle] else middle

        if target > nums[middle]:
            middle += self.searchInsert(nums[middle:], target)
        elif target < nums[middle]:
            middle = self.searchInsert(nums[:middle], target)
        return middle
```
