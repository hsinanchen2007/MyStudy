1.正常解法 找山顶
```
class Solution:
	def validMountainArray(self,A):
		legt=len(A)
		if legt<3 or max(A[:2])==A[0]:
			return False
		flag=True #当到达山顶的时候将其置为False
		for i in range(legt-1):
			if flag:
				if A[i]>A[i+1]:
					flag=False
				elif A[i]==A[i+1]:
					return False
			else:
				if A[i]<=A[i+1]:
					return False
		return not flag #一直上坡的情况下flag最终是True 符合题意的情况下flag最终是False
```

2.使用groupby对上坡和下坡进行分组（因为这条题目没什么特别需要注意的 所以写得自由了一点）
注：评论区和其他大佬的题解都不错 以下代码仅供参考
```
from itertools import groupby
class Solution:
	def validMountainArray(self,A):
		if len(A)<3 or A[0]>=A[1]:
			return False
		groups=[len(tuple(i)) for _,i in groupby(-1 if i<j else 1 for i,j in zip(A[:-1],A[1:]) if i!=j)]
		return len(groups)==2 and sum(groups)==len(A)-1
```

