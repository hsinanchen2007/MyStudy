Py3 972 ms 20.5 MB
```
class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        nums = [i % 2 for i in nums]
        odd_indexes = [-1] + [index for index, value in enumerate(nums) if value == 1] + [len(nums)]
        if len(odd_indexes) < k + 2:
            return 0
        odd_space = [(odd_indexes[i + 1] - odd_indexes[i]) for i in range(len(odd_indexes) - 1)]
        res = 0
        for i in range(len(odd_space) - k):
            res += odd_space[i] * odd_space[i + k]
        return res
```
首先模2转换成01串
记录所有1的位置（奇数的位置），前后加-1和len(nums)相当与数组边界
如果奇数数量不足k 答案为0
作奇数位置的差分，即两个相邻奇数之间的距离
k个连续奇数能贡献的子串数取决于两端的“空间”
数量=左端的左侧空间*右端的右侧空间
