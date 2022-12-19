```python
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # 假定数独有唯一解，但是数独实际上是有可能有多个解的
        # 这里就要用到以bool做dfs/回溯返回值，并加上返回值判断减小深度
        # 判断是否能加进去
        # 1. 扩展加判断 2. 回溯加return
        nums = [str(i) for i in range(1, 10)]
        def isValid(row:int, col:int, num:int):
            for i in range(9):
                # 每一行只能出现一次
                if board[row][i] == num:
                    return False
                # 每一列之恩给你出现一次
                if board[i][col] == num:
                    return False
            # 九宫格？0, 3, 6
            rowStart = (row // 3) * 3
            colStart = (col // 3) * 3
            for i in range(3):
                for j in range(3):
                    if board[rowStart + i][colStart + j] == num:
                        return False
            return True                
        def backTracking(row:int, col:int):
            # 不符合状态
            if col == 9:
                return backTracking(row + 1, 0)
            # 最终状态
            if row == 9:
                return True
            # 只填充空白格
            if board[row][col] != '.':
                # 直接下一个
                return backTracking(row, col + 1)
            else:   
            # 扩展状态
                for addNum in nums:
                    if not isValid(row, col, addNum):
                        continue
                    board[row][col] = addNum
                    if backTracking(row, col + 1):
                        return True
                    board[row][col] = '.'
                else:
                    return False
        backTracking(0, 0)
```