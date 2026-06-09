```
class Solution:    
    def uniquePaths(self, m: int, n: int) -> int:
        '''
        使用一个二维状态数组，思路和“求带权路径”是一样的思路。
        （其实用一维数组就可以了，只是二维数组比较好理解）
        思路：
        status的每个元素存的是每个位置到终点有几条路径。
        具体的：
        我们从终点往回退，很快就能想到status[m-2][n-1] --> status[m-1][n-1]和
        status[m-1][n-2] --> status[m-1][n-1] 只有一条路径。
        接着status[m-2][n-2] --> status[m-1][n-1]呢？显然，status[m-2][n-2]只能先到
        status[m-2][n-1] or status[m-1][n-2]，那么status[m-2][n-2] 的路径数只要
        加上status[m-2][n-1] 和 status[m-1][n-2]就可以了。
        '''
        status = [[0]*n for i in range(m)]
        status[m-1][n-1] = 1
        for i in range(m-1,-1,-1):
            for j in range(n-1,-1,-1):
                if j == n-1 and i == m-1:
                    continue
                else:
                    if i+1 == m:
                        status[i][j] = 1
                    elif j+1 == n:
                        status[i][j] = 1
                    else:
                        status[i][j] = status[i+1][j] + status[i][j+1]
        return status[0][0]
```
