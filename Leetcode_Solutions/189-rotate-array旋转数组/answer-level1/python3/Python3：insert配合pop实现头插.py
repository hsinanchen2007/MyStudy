# **inser()配合pop()实现头插**
```python
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for _ in range(k):
            nums.insert(0,nums.pop())
```
$时间复杂度为O(n)$