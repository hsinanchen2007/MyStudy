```
class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        m = len(matrix)
        n = len(matrix[0])
        ret = [[0 for j in range(n)] for i in range(m)]
        flag = [[0 for j in range(n)] for i in range(m)]
        queue = []
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    flag[i][j] = 1
                    queue.append((i,j,0))
        while queue:
            i,j,k = queue.pop(0)
            if i - 1 >= 0 and flag[i - 1][j] == 0:
                ret[i - 1][j] = k + 1
                flag[i - 1][j] = 1
                queue.append((i - 1,j , k + 1))
            if i + 1 < m and flag[i + 1][j] == 0:
                ret[i + 1][j] = k + 1
                flag[i + 1][j] = 1
                queue.append((i + 1,j , k + 1))
            if j - 1 >= 0 and flag[i][j - 1] == 0:
                ret[i][j - 1] = k + 1
                flag[i][j - 1] = 1
                queue.append((i ,j - 1 , k + 1))
            if j + 1 < n and flag[i][j + 1] == 0:
                ret[i][j + 1] = k + 1
                flag[i][j + 1] = 1
                queue.append((i,j + 1 , k + 1))
        return ret
```[]()
