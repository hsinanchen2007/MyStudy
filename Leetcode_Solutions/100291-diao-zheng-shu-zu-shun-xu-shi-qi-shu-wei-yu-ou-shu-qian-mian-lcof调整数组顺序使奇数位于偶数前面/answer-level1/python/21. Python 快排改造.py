### 解题思路
这道题的思路我觉得应该是非常流畅且自然的，首先这道题是一个排序问题，那么常用的较快的排序方法是快速排序和归并排序，两者都是O(nlogn)的时间复杂度，但是区别在于，快排是从上往下进行，而归并排序是从下往上进行，而从上往下进行的特点是保证（用枢轴分开的）两个部分是相对有序的，以递增排序来说就是，第一次处理使得左半部分都小于枢轴，右半部分都大于枢轴，这个特点恰恰就符合这道题的要求。所以可以根据快排的思路完成这道题。
ps: 这道题中规定两个部分的先后顺序的代码可以封装成一个函数传入，这样更能体现出代码的模块化。

### 代码

```python
class Solution(object):
    def exchange(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        length  = len(nums)
        if length == 0:
            return nums
        temp = nums[0]
        p = 0
        q = length - 1
        while p < q:
            while p < q and nums[q] & 1 == 0:
                q -= 1
            if p < q:
                nums[p] = nums[q]
                p += 1
            while p < q and nums[p] & 1 == 1:
                p += 1
            if p < q:
                nums[q] = nums[p]
                q -= 1
        nums[p] = temp
        return nums
```