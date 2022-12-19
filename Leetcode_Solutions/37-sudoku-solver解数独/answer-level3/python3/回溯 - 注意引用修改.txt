### 解题思路
主要问题是题目判定的board引向的内存空间，而在回溯过程中，找到答案后，可能还会thread继续更改board；

### 代码

```python
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        self.board = board
        self.res = [[0]*9 for ind in range(9)]
        self.empty_tiles = []
        for ir, irow in enumerate(board):
            for ic, icol in enumerate(irow):
                if icol == '.':
                    self.empty_tiles.append((ir, ic))
        self.n_empty = len(self.empty_tiles)

        self.row_check = [[False] * 9 for ind in range(9)]
        self.col_check = [[False] * 9 for ind in range(9)]
        self.block_check = [[False] * 9 for ind in range(9)]

        def is_available(ir:int, ic:int, ival:int) -> bool:
            """Check if the ival is ok in (ir, ic) position
            """
            return ((not self.row_check[ir][ival]) 
                and (not self.col_check[ic][ival]) 
                and (not self.block_check[(ir//3)*3+(ic//3)][ival]))
        
        def mark_val(ir, ic, ival):
            self.row_check[ir][ival] = True
            self.col_check[ic][ival] = True
            self.block_check[(ir // 3)*3 + (ic//3)][ival] = True

        def cancel_val(ir, ic, ival):
            self.row_check[ir][ival] = False
            self.col_check[ic][ival] = False
            self.block_check[(ir // 3)*3 + (ic//3)][ival] = False

        def get_available_candi(ir:int, ic:int) -> list:
            res = []
            for jind in range(9):
                if is_available(ir, ic, jind):
                    res.append(jind)
            return res

        def make_a_board_copy(inp, res):
            for ir, irow in enumerate(inp):
                for ic, icol in enumerate(irow):
                    res[ir][ic] = inp[ir][ic]
            return res

        def dfs(ind:int):
            if ind >= self.n_empty:
                make_a_board_copy(self.board, self.res)
                return
            cur_ir, cur_ic = self.empty_tiles[ind]
            cur_candi = get_available_candi(cur_ir, cur_ic)
            for icand in cur_candi:
                self.board[cur_ir][cur_ic] = str(icand+1)
                mark_val(cur_ir, cur_ic, icand)
                dfs(ind+1)
                cancel_val(cur_ir, cur_ic, icand)

        # init the checklist
        for ir, irow in enumerate(board):
            for ic, icol in enumerate(irow):
                if not icol == '.':
                    ival = int(icol)
                    mark_val(ir, ic, ival-1)

        dfs(0)
        make_a_board_copy(self.res, self.board)
        

```