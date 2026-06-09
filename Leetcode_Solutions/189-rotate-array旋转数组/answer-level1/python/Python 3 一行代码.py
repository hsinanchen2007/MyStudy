### 解题思路
还是切片，但是取个模就可以得到真正的k了，会稍微快一些

### 代码

```python3
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nums[:] = nums[-(k%len(nums)):] + nums[:-(k%len(nums))]
```