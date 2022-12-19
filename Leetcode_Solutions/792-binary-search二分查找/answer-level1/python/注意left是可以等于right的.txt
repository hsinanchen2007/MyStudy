### 解题思路
1、注意left是可以等于right的，当最后只有一个元素的时候，可以这样得到；
2、每次的mid等于(left+right)/2，不是right-left，而是相加

### 代码

```python
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) == 0:
            return -1
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = int((right + left) / 2)

            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
        return -1

```