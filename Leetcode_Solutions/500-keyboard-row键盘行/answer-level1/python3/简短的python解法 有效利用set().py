思路：set的子集
```
class Solution:
	def findWords(self,words):
		_all_=[set(i+i.swapcase()) for i in ("qwertyuiop","asdfghjkl","zxcvbnm")]
		return [i for i in words if any(set(i)<=j for j in _all_)]
```
