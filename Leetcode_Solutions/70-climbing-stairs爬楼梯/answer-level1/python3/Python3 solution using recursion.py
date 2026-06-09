### 代码

```python3
class Solution:
	def climbStairs(self, n: int) -> int:
		if n == 1 or n == 0:
			return 1
		elif n % 2 == 0:
			return (pow(self.climbStairs(n/2), 2) + pow(self.climbStairs(n/2 - 1), 2))
		else:
			return (pow(self.climbStairs((n - 1)/2), 2) + (self.climbStairs((n - 1) / 2) * self.climbStairs((n - 1) / 2 - 1)) * 2)
```