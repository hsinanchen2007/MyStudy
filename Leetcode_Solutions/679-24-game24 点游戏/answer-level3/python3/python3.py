![679.jpg](https://pic.leetcode-cn.com/1bdcc219fc275312d8bd3968802612cd852e6ef65db53e249c2576009634c796-679.jpg)

```
from operator import add,sub,mul
from fractions import Fraction as div
from itertools import permutations as perm
operators=(add,sub,mul,div)
target=24

class Solution:
	def judgePoint24(self, nums: List[int]) -> bool:
		for a,b,c,d in perm(nums):
			for x in operators:
				for y in operators:
					for z in operators:
						try:
							p=z(a,y(b,x(c,d)))==target
						except:
							p=0
						try:
							q=z(x(a,b),y(c,d))==target
						except:
							q=0
						if p or q:
							return True
		return False
```
