### 解题思路
先将列表排序，将列表最大数跟最小数与target进行比较，剩下中间的数依次进行比较

### 代码

```python
class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()   # 先排序
        if max(nums) < target:
            return len(nums)
        if min(nums) > target:
            return 0
        else:
            for i in range(len(nums)):
                if nums[i] < target:
                    continue
                return i
                


```