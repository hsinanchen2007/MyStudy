```python
class Solution:

	def is_palindrome(self, s: str)-> bool:
		l, r = 0, len(s) - 1
		while l < r:
			if s[l] != s[r]: return False
			l = l + 1
			r = r - 1
		return True

	def partition(self, s: str)-> List[List[str]]:
		
		# Time complexity: O(2 * n)
		# Space complexity: O(2 * n)
		
		if s == '': return []	
		if len(s) == 1: return [[s]]
		res = []
		for i in range(len(s)):
			if self.is_palindrome(s[:i + 1]):
				left = s[: i + 1]
				right_arr = self.partition(s[i + 1:])
				if right_arr == []:
					res.append([left])
				for right in right_arr:
					res.append([left] + right)
		return res
```