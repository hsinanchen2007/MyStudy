## 解题思路

要想要个数最少，总和是一定的，所以尽量选大的即可。排序之后再扫描

时间复杂度`O(n logn)` 空间复杂度`O(1)`


## 代码

```python
class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        nums.sort(reverse=True)
        s = sum(nums)
        t_s = 0
        for i, x in enumerate(nums):
            t_s += x
            if t_s > s // 2:
                return nums[:i + 1]

```