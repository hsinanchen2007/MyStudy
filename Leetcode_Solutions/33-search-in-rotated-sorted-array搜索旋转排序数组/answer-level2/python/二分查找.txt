### 解题思路
1. 因为有序数组发生了旋转，这题和一般的有序二分查找的差别在于二分的条件不同。
2. 旋转后的数组二分后肯定有一半是有序数组，有一半是旋转数组。
3. 通过判断左边第一个值`left`和中间的值的`middle`的大小关系
4. 如果left<=middle，那么有序数组在左边
5. 如果left>middle， 那么有序数组在右边

### 代码

```python
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) == 0: return -1
        left = 0
        right = len(nums) - 1
        while(left <= right):
            middle = left + (right - left) // 2
            if nums[middle] == target: return middle
            elif nums[middle] >= nums[left]:
                if target >= nums[left] and target < nums[middle]:
                    right = middle -1
                else:
                    left = middle + 1
            else :
                if target > nums[middle] and target <= nums[right]:
                    left = middle + 1
                else:
                    right = middle - 1
        return -1

```