### 解题思路
本质是排序算法，只是在判断大小的地方，把直接通过数学<、>的地方改成compare函数；可以使用快速排序实现

### 代码

```python

```python
class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        self.quickSort(nums, 0, len(nums) - 1)
        # 边界case
        if nums[0] == 0:
            return "0"
        return "".join((str(n) for n in nums))

    def quickSort(self, nums, L, R):
        if L < R:
            p = self.partition(nums, L, R)
            self.quickSort(nums, L, p - 1)
            self.quickSort(nums, p + 1, R)

    def partition(self, nums, L, R):
        plv = nums[L]

        i = L + 1
        j = R

        while i <= j:
            if self.custom_compare(nums[i], plv) == -1:
                i += 1
                continue

            if self.custom_compare(nums[j], plv) == 1:
                j -= 1
                continue

            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1

        if self.custom_compare(nums[j], plv) == -1:
            nums[j], nums[L] = nums[L], nums[j]
        return j

    def custom_compare(self, a, b):
        a_b = int('%d%d' % (a, b))
        b_a = int('%d%d' % (b, a))

        if a_b > b_a:
            return -1
        if a_b < b_a:
            return 1
        return 0
```
