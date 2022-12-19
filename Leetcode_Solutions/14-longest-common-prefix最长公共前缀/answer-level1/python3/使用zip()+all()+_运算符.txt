思路：依次对每一个字符串的各位字符进行比较
```
class Solution:
	def longestCommonPrefix(self,strs):
		ans=""
		for i in zip(*strs):
			t=i[0]
			if all(j==t for j in i):
				ans+=t
			else:
				break
		return ans
```
