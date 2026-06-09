### 解题思路
思路与54题类似，逐行逐列模拟。

### 代码

```python3
class Solution:
    def generateMatrix(self, n: int) -> list:
        matrix = [[0 for _ in range(n)] for _ in range(n)]
        col_m, row_m = n, n - 1
        flag = 0
        number, location = 0, [0, 0]
        while number < n*n:
            if flag == 0:
                for i in range(col_m):
                    number += 1
                    matrix[location[0]][location[1]+i] = number
                col_m -= 1
                location = [location[0]+1,location[1]+col_m]
            elif flag == 1:
                for i in range(row_m):
                    number += 1
                    matrix[location[0]+i][location[1]] = number
                row_m -= 1
                location = [location[0]+row_m,location[1]-1]
            elif flag == 2:
                for i in range(col_m):
                    number += 1
                    matrix[location[0]][location[1]-i] = number
                col_m -= 1
                location = [location[0]-1,location[1]-col_m]
            else:
                for i in range(row_m):
                    number += 1
                    matrix[location[0]-i][location[1]] = number
                row_m -= 1
                location = [location[0]-row_m,location[1]+1]
            flag = (flag + 1) % 4
        return matrix
        


```