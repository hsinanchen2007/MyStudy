不用想的那么复杂，其实就是遍历两次就可以了。

每个非0点到0的距离，跟它上下左右到0的距离有关，所以第一次遍历先将左上两个位置的非0点最小者加1更改。

这样就是从左上往右下看，非0点到0的最短距离，但是这样还不知道从右下到左上看的最短距离。

所以再从右下到左上遍历，注意这次更新除了要取右下两个点的最短距离之外，还要跟当前位置的点做一次最小值比较，因为右下可能距离更远。

```
class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                l,t= 10001,10001
                if matrix[i][j] != 0:
                    if i > 0:
                        t = matrix[i - 1][j]
                    
                    if j > 0:
                        l = matrix[i][j - 1]
                    
                    matrix[i][j] = min(l,t) + 1
        
        for i in range(len(matrix) - 1, -1 ,-1):
            for j in range(len(matrix[0]) - 1, -1, -1):
                r,b = 10001,10001
                if matrix[i][j] != 0:
                    if i < len(matrix) - 1:
                        b = matrix[i + 1][j]

                    if j < len(matrix[0]) - 1:
                        r = matrix[i][j + 1]

                    matrix[i][j] = min(matrix[i][j], min(r,b) + 1)
        return matrix
```
