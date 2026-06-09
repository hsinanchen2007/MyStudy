```
	def generate(self, numRows: int) -> List[List[int]]:
		r = [[]]*numRows
		for i in range(numRows):
			r[i] = [0]*(i+1)
			if i==0:
				r[0][0] = 1
			else:
				for j in range(i+1):
					if j==0 or j==i:
						r[i][j] = 1
					else:					
						r[i][j] = r[i-1][j-1] + r[i-1][j]
		return r
```
