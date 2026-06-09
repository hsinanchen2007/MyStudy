### 解题思路
python 直接找最终位置

### 代码

```python
class Solution(object):
	def missingTwo(self, nums):
		"""
		:type nums: List[int]
		:rtype: List[int]
		"""
		nums.append(0)
		nums.append(0)

		i = 0
		n = len(nums)

		while i < n:
			if nums[i] != 0 and nums[i] != i+1:
				t = nums[i]-1
				nums[i], nums[t] = nums[t], nums[i]
			else:
				i += 1

		ans = []
		for i in xrange(n):
			if nums[i] == 0:
				ans.append(i+1)

		return ans
```