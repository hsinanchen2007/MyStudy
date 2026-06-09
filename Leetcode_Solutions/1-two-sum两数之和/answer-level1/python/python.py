### 解题思路
字典寻查方法

### 代码

```python3
class Solution:
	def twoSum(self,nums,target):
		d = {}
		n = len(nums)
		for x in range(n):
			if target - nums[x] in d:
				return d[target-nums[x]],x
			else:
				d[nums[x]] = x
```