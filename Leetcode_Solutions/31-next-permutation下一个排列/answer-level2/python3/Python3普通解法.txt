找到满足nums[i] < nums[i+1]的最大的i。

如果不存在，则整个数组是（不严格）倒序的，需要全部反转。

否则，先反转nums[i+1:]，再从nums[i+1:]中找到第一个比nums[i]大的元素（此时nums[i+1:]已经正序排列）与nums[i]交换。

```
class Solution:
    def nextPermutation(self, nums):
        """
        Do not return anything, modify nums in-place instead.
        """

        n = len(nums)

        if n <= 1:
            return nums

        last = -1
        cur = 0
        next_ = 1

        while next_ <= n - 1:
            if nums[cur] < nums[next_]:
                last = cur
            cur += 1
            next_ += 1

        if last == -1:
            self.reverse_list(nums, 0, n - 1)
        else:
            self.reverse_list(nums, last + 1, n - 1)
            self.exchange_element_bigger_than_some(nums, last)

    @staticmethod
    def reverse_list(l, i, j):
        while i < j:
            l[i], l[j] = l[j], l[i]
            i += 1
            j -= 1

    @staticmethod
    def exchange_element_bigger_than_some(l, i):
        m = l[i]
        for j, n in enumerate(l[i+1:]):
            if n > m:
                l[i + j + 1], l[i] = m, n
                return
```