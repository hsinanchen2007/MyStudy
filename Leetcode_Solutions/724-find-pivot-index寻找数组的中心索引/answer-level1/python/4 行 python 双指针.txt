```python
class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        l, r, diff = 0, 0, [0] * len(nums)
        for i, j in zip(range(len(nums)), range(len(nums) - 1, -1, -1)):
            diff[i] += l; l += nums[i]; diff[j] -= r; r += nums[j]
        return diff.index(0) if 0 in diff else -1
```
- 本题利用双指针 i，j 双向遍历数组。
- l 记录当前索引左边所有数字之和，r 记录右边的和
- diff 记录当前索引左边所有数字之和 - 右边所有数字之和，中心索引左右和相等，diff[中心索引] 为 0