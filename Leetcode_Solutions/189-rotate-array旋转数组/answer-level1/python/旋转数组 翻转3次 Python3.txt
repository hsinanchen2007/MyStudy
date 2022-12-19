### 解题思路
执行用时 :48 ms, 在所有 Python3 提交中击败了74.74%的用户
内存消耗 :13.9 MB, 在所有 Python3 提交中击败了97.92%的用户

### 代码

```python3
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k = k % len(nums)
        if k == 0:
            return nums
        nums[:] = nums[::-1]
        nums[:k] = nums[k-1::-1]
        nums[k:] = nums[:k-1:-1]
```