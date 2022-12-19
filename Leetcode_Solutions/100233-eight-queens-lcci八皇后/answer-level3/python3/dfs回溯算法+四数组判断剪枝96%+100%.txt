### 解题思路
执行用时 :96.75%
内存消耗 :100.00%

dfs+回溯

从第一行开始放，一直放到最后一行  
用四个bool数组判断行，列，左对角线，右对角线有没有皇后  
dfs出来记得把状态恢复原位
### 代码

```python3
class Solution:
    def solveNQueens(self, n: int):
        PUZZLE_SIZE = n
        puzzle = [[False for col in range(PUZZLE_SIZE)] for row in range(PUZZLE_SIZE)]
        occupy_row = [False] * PUZZLE_SIZE
        occupy_col = [False] * PUZZLE_SIZE
        occupy_right_diagonal = [False]*(PUZZLE_SIZE*2-1)
        occupy_left_diagonal = [False]*(PUZZLE_SIZE*2-1)
        ans = []

        def get_ans():
            nonlocal ans
            graph = []
            for col in range(PUZZLE_SIZE):
                str_col = ""
                for row in range(PUZZLE_SIZE):
                    if puzzle[col][row]:
                        str_col += 'Q'
                    else:
                        str_col += '.'
                graph.append(str_col)
            ans.append(graph)

        def cal_right_diagonal(row: int, col: int) -> int:
            return col-row+PUZZLE_SIZE-1

        def cal_left_diagonal(row: int, col: int) -> int:
            return col+row

        def dfs(current_row: int):
            nonlocal puzzle, occupy_col, occupy_row, occupy_left_diagonal, occupy_right_diagonal, PUZZLE_SIZE
            if (current_row == PUZZLE_SIZE - 1):
                get_ans()
            nxt_row = current_row+1
            for nxt_col in range(PUZZLE_SIZE):
                if occupy_col[nxt_col]:
                    continue
                if occupy_right_diagonal[cal_right_diagonal(nxt_row, nxt_col)]:
                    continue
                if occupy_left_diagonal[cal_left_diagonal(nxt_row, nxt_col)]:
                    continue
                puzzle[nxt_row][nxt_col] = True
                occupy_row[nxt_row] = True
                occupy_col[nxt_col] = True
                occupy_right_diagonal[cal_right_diagonal(nxt_row, nxt_col)] = True
                occupy_left_diagonal[cal_left_diagonal(nxt_row, nxt_col)] = True
                dfs(nxt_row)
                puzzle[nxt_row][nxt_col] = False
                occupy_row[nxt_row] = False
                occupy_col[nxt_col] = False
                occupy_right_diagonal[cal_right_diagonal(nxt_row, nxt_col)] = False
                occupy_left_diagonal[cal_left_diagonal(nxt_row, nxt_col)] = False

        dfs(-1)
        return ans


if __name__ == "__main__":
    my = Solution()
    print(my.solveNQueens(4))

```