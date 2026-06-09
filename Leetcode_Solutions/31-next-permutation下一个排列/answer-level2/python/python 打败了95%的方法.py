### 解题思路
看到这个题目刚开始我也毫无头绪。这个题目一定要想清楚如何得到比当前大的下一个数字。
首先，从后向前遍历，找到第一个前项小于后项的位置。这个位置是我们要替换的记为`i`。此时，`nums[i+1:]`一定是按照降序排列好的。
然后，寻找如何替换。我们要找到`nums[i+1:]`中大于`nums[i]`的最小项。
最后完成，交换就可`nums[i], nums[j] = nums[j], nums[i]`，并且对完成交换后的`nums[i+1:]`进行升序排序。
还需要考虑一个异常情况，也就是`[3,2,1]`，只需要倒叙即可
最差情况下时间复杂度是$O(2n)$
### 代码

```python
class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if n < 2:
            return nums
        i = n-2
        while i>=0 :
            if nums[i] < nums[i+1]:
                for j in range(i+1,n):
                    if nums[i] >= nums[j]:
                        j -= 1
                        break
                nums[i], nums[j] = nums[j], nums[i]
                nums[i+1:] = sorted(nums[i+1:])
                break
            i -= 1
        if i == -1:
            nums.reverse()
```