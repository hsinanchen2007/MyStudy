### 解题思路
1、二分查找，定义两个数，分别为数组的最小和最大索引，然后算出数组索引的中间值mid
2、在while循环中，用arr[mid]与传入的target值进行对比，然后移动下标。


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
            return False

        low = 0
        height = len(nums) -1

        while low <= height:
            mid = (low + height) / 2

            if target > nums[mid]:
                low = mid + 1
            elif target < nums[mid]:
                height = mid -1
            else:
                return mid
        return -1
```