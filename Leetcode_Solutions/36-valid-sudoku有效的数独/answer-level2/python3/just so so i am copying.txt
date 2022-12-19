```
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        def cubeNum(i, j):
            r = i // 3
            c = j // 3
            return r*3 + c

        # 每行数字访问表(打成一行为标记一行)
        rowsUsed = [[False for i in range(10)] for j in range(9)]
        # 每列数字访问表(打成一行为标记一列)
        colsUsed = [[False for i in range(10)] for j in range(9)]
        # 每一个3*3宫内访问表(打成一行为标记一宫格)
        cubesUsed = [[False for i in range(10)] for j in range(9)]

        # 标记已经有数值的元素 如果已经遍历过了，说明不是有效数组
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    continue
                num = int(board[i][j])
                if not rowsUsed[i][num] and not  colsUsed[j][num] and not cubesUsed[cubeNum(i,j)][num]:
                    rowsUsed[i][num] = True
                    colsUsed[j][num] = True
                    cubesUsed[cubeNum(i,j)][num] = True
                else:
                    return False
        return True

```
