### 解题思路
显然[9,9,9,9,8,8,8,8,8]返回False，方法：桶排计数后，求gcd即可
执行用时 :44 ms, 在所有 Python3 提交中击败了94.56%的用户
内存消耗 :13.9 MB, 在所有 Python3 提交中击败了5.21%的用户
### 代码
一行解决
```python3
class Solution:
	def hasGroupsSizeX(self,deck:List[int]) -> bool:
		return reduce(gcd,collections.Counter(deck).values())>1
```

下面的代码是自行求了一遍gcd
```python3
class Solution:
	def hasGroupsSizeX(self,deck:List[int]) -> bool:
		l=list(collections.Counter(deck).values())
		G=l[0]
		for i in l:G=gcd(G,i)
		return G>1
```


```python3
class Solution:
	def hasGroupsSizeX(self,deck:List[int])->bool:
		import numpy,collections
		return numpy.gcd.reduce(list(collections.Counter(deck).values()))>1
```
这个的代码在本地能过，oj可能是是因为不支持numpy.gcd.reduce导致运行错误