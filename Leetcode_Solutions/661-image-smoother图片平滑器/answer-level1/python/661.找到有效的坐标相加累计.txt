### 解题思路
1. 给出一个中心的周围八个值的相对坐标。
2. 如果存在有效的坐标`0 <= dx < row and 0 <= dy < col`则相加且累计数目。

### 代码

```python3
class Solution:
    def imageSmoother(self, M: List[List[int]]) -> List[List[int]]:
        row, col = len(M), len(M[0])
        res = [[0 for i in range(col)] for j in range(row)]

        def calc(x, y):
            sum_ = 0
            num = 0
            steps = [[0,0], [-1,0], [-1,1], [0,-1], [0,1], [1,-1],[1,0],[1,1], [-1,-1]]
            for item in steps:
                dx = x + item[0]
                dy = y + item[1]

                if 0 <= dx < row and 0 <= dy < col: # 提取有效的坐标进行相加和累计
                    sum_ += M[dx][dy]
                    num += 1
            
            return sum_//num

        for i in range(row):
            for j in range(col):
                res[i][j] = calc(i, j)
        
        return res
```