```
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if len(matrix) == 0: return []
        directions = [[0, 1], [1, 0], [0, -1], [-1, 0]] # 分别对应四个方向，右下左上
        m, n = len(matrix), len(matrix[0])
        numcount = m * n    # 矩阵数字总个数
        tag = 0     # 方向计数器
        res = []    # 输出列表
        x, y = 0, -1
        while numcount:
            while True:
                tmp1, tmp2 = x+directions[tag][0], y + directions[tag][1]
                if 0<=tmp1<m and 0<=tmp2<n and matrix[tmp1][tmp2] != None:
                    x, y = tmp1, tmp2
                else:
                    break
                res.append(matrix[x][y])
                matrix[x][y] = None
                numcount -= 1
            tag = (tag + 1) % 4


        return res
```
