## 思路:

刚看到这题，这不就是一遍遍历吗，刷刷刷，写出来下面的代码

```python
class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = [float("-inf")] + nums + [float("-inf")]
        n = len(nums)
        for i in range(1, n - 1):
            if nums[i - 1] < nums[i] and nums[i] > nums[i + 1]:
                return i - 1
```

但是， 题目要求是 $O(log N)$,明显这是$O(n)$的，还有一种$O(n)$一次遍历算法

```python
class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i in range(1, len(nums)):
            if nums[i - 1] > nums[i]:
                return i - 1
        return len(nums) - 1
```

很神奇吧，言归正传！这题要求局部最大值，又要用二分法，参考链接 [^1]

我不是太明白， 但是大家可以用极端角度考虑一下，模拟一下过程，找找感觉！

如果这个数组按顺序排列的？如果这个数组为 `[1, 2]`呢？有谁可以把它说明白吗？

```python
class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left = 0
        right = len(nums) - 1
        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] < nums[mid + 1]:
                left = mid + 1 
            else:
                right = mid
        return left
```



[^1]: <https://leetcode.com/problems/find-peak-element/discuss/50232/Find-the-maximum-by-binary-search-(recursion-and-iteration)>