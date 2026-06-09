### 解题思路
code

### 代码

```python3
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nums[:] = nums[-k%len(nums):] + nums[:-k%len(nums)]
```