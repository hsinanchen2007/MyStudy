```python
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        return [[n] + sub for i, n in enumerate(nums) for sub in self.permute(nums[:i] + nums[i+1:])] or [nums]
```
- 每次固定第一个数字递归地排列数组剩余部分
- python 有内置函数可以直接实现

	```python
	class Solution:
	    def permute(self, nums: List[int]) -> List[List[int]]:
		from itertools import permutations
		return list(permutations(nums))
	```
