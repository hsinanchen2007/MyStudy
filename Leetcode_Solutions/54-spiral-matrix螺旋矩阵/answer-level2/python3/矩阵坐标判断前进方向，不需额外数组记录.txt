1. 设置当前访问状态（上，下，左，右），按顺序设置状态，根据状态对当前坐标进行相应加减；
2. 拐点的判断是依据当前访问所在坐标值与整个矩阵大小的关系。

（不需要另一个数组来记录是否访问过，只需要一个count来计算当前访问过的个数等于矩阵里数字总数即可。）

```
def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if len(matrix) == 0:
            return matrix
        
        m, n = len(matrix), len(matrix[0])
        if m == 1 or n == 1:
            return [x for row in matrix for x in row]
        
        action = {'right': (0, 1), 'down': (1, 0), 'left': (0, -1), 'up': (-1, 0)}
        count, total = 0, m*n
        res = []
        
        i, j = 0, 0
        while count < total:
            res.append(matrix[i][j])
            count += 1
            if i <= j and i+j == n-1 and act == 'right':
                act = 'down'
            elif m-i == n-j and i != 0 and act == 'down':
                act  = 'left'
            elif i > j and i+j == m-1 and act == 'left':
                act  = 'up'
            elif (i-j == 1 and act == 'up') or i == 0:
                act  = 'right'
            i += action[act][0]
            j += action[act][1]
        
        return res
```

