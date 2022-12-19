****
```
class Solution:
	def generateMatrix(self, n: int):
		res = [[0]*n for _ in range(n)]
		self.a = 1
		def helper(n,i):
			if not n: return 
			for j in range(i,n):
				res[i][j] = self.a
				self.a += 1
			for j in range(i+1,n):
				res[j][n-1] = self.a
				self.a += 1
			for j in range(n-2,i-1,-1):
				res[n-1][j] = self.a
				self.a += 1
			for j in range(n-2,i,-1):
				res[j][i] = self.a
				self.a += 1		
			helper(n-1,i+1)
		helper(n,0)
		return res
```

