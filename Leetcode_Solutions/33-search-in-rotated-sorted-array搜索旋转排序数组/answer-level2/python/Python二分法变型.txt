### 解题思路
这道题看到要求O(logn)时间复杂度首先就应该想到用二分法，而且序列可以看做是局部有序，这也可以看做是使用二分法的一个条件，只不过需要对二分法进行改动。
这道题就是一个分类讨论的题，多列几个样例就能写出来判断条件。
对于有序无重复数字的序列来说，有nums[left] < nums[mid] < nums[right]
而对于这道题有可能存在nums[left] > nums[mid] < nums[right]或者nums[left] < nums[mid] > nums[right]，我们只需要对一半区间进行讨论即可。

### 代码

```python
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        left, right = 0, len(nums) - 1
        mid = (left + right) // 2
        while left <= right:
            print(left, mid, right)
            if target == nums[mid]:
                return mid
            if nums[right] < nums[mid] and (target > nums[mid] or target <= nums[right]) or nums[right] > nums[mid] and target > nums[mid] and target <= nums[right]:
                left = mid + 1
            else:
                right = mid - 1
            mid = (left + right) // 2
        print(left, mid, right)
        return -1
```