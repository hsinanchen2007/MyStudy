### 解题思路
暴力

### 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        ext_board = []
        row_cnt = len(board)
        colum_cnt = len(board[0])
        zero_row = [0] * (colum_cnt + 2)
        ext_board.append(zero_row)
        for _ in board:
            tmp_list = []
            tmp_list.append(0)
            tmp_list.extend(_)
            tmp_list.append(0)
            ext_board.append(tmp_list)
        ext_board.append(zero_row)
        i = 1
        j = 1
        result_board = []
        while i <= row_cnt:
            result_row = []
            while j <= colum_cnt:
                sum = ext_board[i - 1][j - 1] + ext_board[i - 1][j] + ext_board[i - 1][j + 1] + ext_board[i][j - 1] + \
                      ext_board[i][j + 1] + ext_board[i + 1][j - 1] + ext_board[i + 1][j] + ext_board[i + 1][j + 1]
                if ext_board[i][j] == 1:
                    if sum < 2:
                        result_row.append(0)
                    elif 2 <= sum <= 3:
                        result_row.append(1)
                    else:
                        result_row.append(0)
                if ext_board[i][j] == 0:
                    if sum == 3:
                        result_row.append(1)
                    else:
                        result_row.append(0)
                j = j + 1
            i = i + 1
            j = 1
            result_board.append(result_row)
        for i in range(row_cnt):
            for j in range(colum_cnt):
                board[i][j] = result_board[i][j]
```

![image.png](https://pic.leetcode-cn.com/42039b657873b368268a1f79e692e44265da37423017f2c5d7845ef67f6f6440-image.png)
