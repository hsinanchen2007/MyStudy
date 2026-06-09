```
from itertools import accumulate
class Solution:
	def canThreePartsEqualSum(self,A):
		total,accu=sum(A),accumulate(A[:-1])
		goal=total//3
		return any(i==goal for i in accu) and any(i==goal*2 for i in accu) or False
		#可以把后面两行合并成一行
```

```python []
#手动实现
class Solution:
	def canThreePartsEqualSum(self,A):
		total=sum(A)
		if not total%3:
			goal=total//3
			cur_sum=0
			for i,j in enumerate(A):
				cur_sum+=j
				if cur_sum==goal:
					cur_sum=0
					for i in A[i+1:-1]:
						cur_sum+=i
						if cur_sum==goal:
							return True
		return False
```
```golang []
//手动实现
func canThreePartsEqualSum(A []int) bool {
	total:=0
	for _,i:=range A {
		total=total+i
	}
	if total%3==0 {
		cur_sum,goal:=0,total/3
		for i,j:=range A {
			cur_sum=cur_sum+j
			if cur_sum==goal {
				cur_sum=0
				for _,v:=range A[i+1:len(A)-1] {
					cur_sum=cur_sum+v
					if cur_sum==goal {
						return true
					}
				}
			}
		}
	}
	return false
}
```

