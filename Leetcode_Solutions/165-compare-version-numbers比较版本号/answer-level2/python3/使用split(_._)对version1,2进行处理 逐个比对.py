最初做完后看了看题解们 发现和powcai大佬想法基本上是一样的 代码如下：
```
from itertools import zip_longest
class Solution:
	def compareVersion(self,version1,version2):
		v1=(int(i) for i in version1.split("."))
		v2=(int(i) for i in version2.split("."))
		for i,j in zip_longest(v1,v2,fillvalue=0):
			if i>j:
				return 1
			elif i<j:
				return -1
		return 0
```
后来看见大佬们都在拼行数 也就想了想能不能尽量压缩 于是有了如下代码(并不美观也显得刻意效率还差点 仅作参考)：
```
from itertools import zip_longest
class Solution:
	def compareVersion(self,version1,version2):
		try: return [1 if i>j else -1 for i,j in zip_longest(map(int,version1.split(".")),map(int,version2.split(".")),fillvalue=0) if i!=j][0]
		except: return 0
```