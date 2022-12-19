### 解题思路
把N当字符字典对待，构造与N同长度的范围内所有2的幂的字符字典，判断字典是否相等即可
### 代码

```python
class Solution(object):
	def reorderedPowerOf2(self, N):
		if N == 1:
			return True
		def split(N):
			sp = {}
			for char in str(N):
				if char in sp:
					sp[char] += 1
				elif char not in sp:
					sp[char] = 1
			return sp
		l = len(str(N))
		x = 2
		while len(str(x)) != l:
			x = x*2
		sp_N = split(str(N))
		while len(str(x)) == l:
			sp_x = split(str(x))
			if sp_N == sp_x:
				return True
			x = x*2

		return False
```