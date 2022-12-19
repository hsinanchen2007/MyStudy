```python
class Solution:
	# [1, 3, 4, 2, 2] (n == 4)
	def findDuplicate(self, nums: List[int]) -> int:
		l, r = 0, len(nums) - 1
		while l < r:
			mid = (l + r) >> 1
			cnt = 0
			for num in nums:  cnt += num <= mid
			if cnt > mid: r = mid
			else: l = mid + 1
		return l
```