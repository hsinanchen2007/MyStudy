### 解题思路
当 k % len(nums) == 0 意味着数组的旋转结果还是常态，没有意义返回
否则交换数据要旋转的数据即可，eg： a, b = b, a 无需申请第三个变量
### 代码
```python3
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k = k % len(nums)
        if k == 0:
            return
        nums[:-k], nums[-k:] = nums[-k:], nums[:-k]
        return
```