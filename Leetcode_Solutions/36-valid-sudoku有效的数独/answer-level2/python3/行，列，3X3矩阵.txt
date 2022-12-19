### 解题思路
就是按照正常思路来判断的，也没什么巧

### 代码

```python3
class Solution:
    def isValidSudoku(self, board):
        length = 9
        for i in range(length):
            for j in range(length):
                if board[i][j].isdigit():
                    num = board[i][j]
                    # 判断行和列,只判断往右下方向的了
                    for k in range(i + 1, 9):
                        if board[k][j] == num:
                            # print("1:" + str(k) + ","+ str(j))
                            return False
                    for k in range(j + 1, 9):
                        if board[i][k] == num:
                            # print("2:" + str(i) + "," + str(k))
                            return False
                    # 然后来判断所在的3×3里面
                    edge = [0, 3, 6, 9]
                    for row_edge in range(1, 4):
                        if edge[row_edge -1] <= i < edge[row_edge]:
                            for col_edge in range(1, 4):
                                if edge [col_edge - 1] <= j  < edge[col_edge]:
                                    # 这个就不能只往右下角看了，会看不全的
                                    for k in range(edge[row_edge -1], edge[row_edge]):
                                        for l in range(edge[col_edge - 1], edge[col_edge]):
                                            if k != i and l != j:
                                                if board[k][l] == num:
                                                    # print("3:" + str(k) + "," + str(l))
                                                    return False
        return True
```