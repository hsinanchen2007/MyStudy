### 解题思路
不能回头，完全可以用标记数组

### 代码

```python3
def digitsum(n):
    return digitsum(n//10)+n%10 if n else 0

class Solution:
	def movingCount(self,m:int,n:int,k:int)->int:
		vis=set([(0,0)])
		for i in range(m):
			for j in range(n):
				if((i-1,j)in vis or(i,j-1)in vis)and digitsum(i)+digitsum(j)<=k:
					vis.add((i,j))
		return len(vis)
```
```python3
def digitsum(n):return digitsum(n//10)+n%10 if n else 0

class Solution:
	def movingCount(self,m:int,n:int,k:int)->int:
		import numpy
		L=[[0]*n for _ in range(m)]
		L[0][0]=1
		for i in range(m):
			for j in range(n):
				if digitsum(i)+digitsum(j)<=k and (i and L[i-1][j]or j and L[i][j-1]):L[i][j]=1
		return int(numpy.array(L).sum())
```
