```python
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        res = 0
        dic_left = {}
        dic_right = {}
        for num in nums:
            if num in dic_left or num in dic_right: continue
            left = dic_left[num  - 1] if num - 1 in dic_left else num
            right = dic_right[num + 1] if num + 1 in dic_right else num
            res = max(res, right - left + 1)
            dic_left[num] = left
            dic_right[num] = right
            dic_right[left] = right
            dic_left[right] = left

        return res
```