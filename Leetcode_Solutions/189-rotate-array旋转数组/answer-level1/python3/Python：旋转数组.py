### 解题思路
说实话，外部空间肯定是O(n)了，不过符合Python的思路

### 代码

```python3
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nums[:]=nums[-k%len(nums):]+nums[:-k%len(nums)]
```