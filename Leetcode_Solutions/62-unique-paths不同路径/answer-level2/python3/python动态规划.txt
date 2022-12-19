### 解题思路
此处撰写解题思路
考虑任意的点dps[i][j]，对于这个点，可以到达该点的点有两个，分别是dps[i-1][j]和dps[i][j-1]，所以推导式为dps[i][j] = dps[i-1][j]+dps[i][j-1], 而且在特殊情况i==0和j==0的情况下，只有一跳路径可以到达该点。根据以上思路 就可以解出该题。


### 代码

```python
class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        dps =[[0 for i in range(n)] for j in range(m)] 
        dps[0][0] = 0
        for i in range(0,m):
            for j in range(0,n):
                if i == 0:
                    dps[i][j]=1
                    continue
                if j == 0:
                    dps[i][j] = 1
                    continue
                dps[i][j] = dps[i - 1][j] + dps[i][j - 1]
      
      
         
        return dps[m-1][n-1]
        
    
            
                
```