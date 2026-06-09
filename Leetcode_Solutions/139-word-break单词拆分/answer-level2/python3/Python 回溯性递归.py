### 解题思路
学会用回溯性递归
学会用
import functools
@functools.lru_cache(None)

### 代码

```python3
class Solution:
	def wordBreak(self, s: str, wordDict) -> bool:
		import functools
		@functools.lru_cache(None)
		def wordpiece(s):
			if not s:
				return True
			res = False
			for i in range(len(s)):
				if (s[0:i + 1] in wordDict):
					res = res or wordpiece(s[i + 1:])
			return res

		return wordpiece(s)

```