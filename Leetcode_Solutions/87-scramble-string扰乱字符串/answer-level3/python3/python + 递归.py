```python
from functools import lru_cache
class Solution:
	@lru_cache(None)
	def isScramble(self, s1: str, s2: str) -> bool:
		s2_reverse = s2[::-1]
		if s1 == s2 or s1 == s2_reverse : return True
		elif collections.Counter(s1) != collections.Counter(s2): return False
		for i in range(1,len(s1)):
			if self.isScramble(s1[:i], s2[:i]) and self.isScramble(s1[i:], s2[i:]): return True
			if self.isScramble(s1[:i], s2_reverse[:i]) and self.isScramble(s1[i:], s2_reverse[i:]): return True
		return False
```