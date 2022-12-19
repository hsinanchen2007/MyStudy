```python
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for _ in range(k % len(nums)): nums[-1:], nums[:0] = [], nums[-1:]
```
- 时间复杂度 = O(k % len(nums))，空间复杂度 = O(1)
```python
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nums[-(k % len(nums)):], nums[:0] = [], nums[-(k % len(nums)):]
```
- 时间复杂度 = O(1)，空间复杂度 = O(k % len(nums))