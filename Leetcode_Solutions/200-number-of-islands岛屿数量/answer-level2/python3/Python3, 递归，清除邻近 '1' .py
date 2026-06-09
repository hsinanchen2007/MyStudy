*对数组遍历，遇到 '1' 便总数加 1 ，并且把所有和连在一起 '1'变为 '0' ,便可去除相连项。*```

```
class Solution:	
	def numIslands(self, x):
        #给外边加一圈 '0'
		if x==[] or x==['0']: return 0
		if x==['1']: return 1
		x = [['0']*len(x[0])] + x + [['0']*len(x[0])]	
		for i in range(len(x)):
			x[i].insert(0,'0')	
			x[i].insert(len(x[0]),'0')		
		s = 0	
		y = x	
        #把连着的 '1' 全变成 '0'
		def df(x,i,j):
			if(x[i-1][j]!='1' and x[i+1][j]!='1' and x[i][j-1]!='1' and
				x[i][j+1]!='1'):  return 
			if x[i-1][j]=='1':
				x[i-1][j]='0'
				df(x,i-1,j)
			if x[i+1][j]=='1':
				x[i+1][j]='0'
				df(x,i+1,j)
			if x[i][j-1]=='1':
				x[i][j-1]='0'
				df(x,i,j-1)
			if x[i][j+1]=='1':
				x[i][j+1]='0'
				df(x,i,j+1)
		for i in range(1,len(x)-1):
			for j in range(1,len(x[0])-1):
				if x[i][j]=='1':
					df(x,i,j)
					s += 1										   
		return s	
```

