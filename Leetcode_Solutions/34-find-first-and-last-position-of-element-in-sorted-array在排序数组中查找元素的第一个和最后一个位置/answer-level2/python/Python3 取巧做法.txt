```python []
def searchRange(self, nums: List[int], target: int) -> List[int]:
	def findnum(nums, t):
		mid, left, right = -1, 0, len(nums) - 1
		while left <= right:
			mid = (left + right) // 2
			if nums[mid] < t:
				left = mid + 1
			elif nums[mid] > t:
				right = mid - 1
			else:
				return mid
	
	if target not in nums:
		return [-1, -1]
	nums = sorted(nums + [target + 0.5, target - 0.5])
	return [findnum(nums, target - 0.5), findnum(nums, target + 0.5) - 2]
```
