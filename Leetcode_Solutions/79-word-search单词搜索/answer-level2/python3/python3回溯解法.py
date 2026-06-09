### 解题思路
python3回溯解法

### 代码

```python3
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if not board:
            return False
        row_len = len(board)
        col_len = len(board[0])
        def isElemOk(row_index, col_index, cur_word):
            if len(cur_word) == 1:
                return board[row_index][col_index] == cur_word
            if board[row_index][col_index] == cur_word[0]:
                #重点记得这个标记位要设置一下
                tmp_val = board[row_index][col_index]
                board[row_index][col_index] = -1
                if row_index > 0 and isElemOk(row_index-1, col_index, cur_word[1:]):
                    return True
                if row_index < row_len-1 and isElemOk(row_index+1, col_index, cur_word[1:]):
                    return True
                if col_index > 0 and isElemOk(row_index, col_index-1, cur_word[1:]):
                    return True
                if col_index < col_len-1 and isElemOk(row_index, col_index+1, cur_word[1:]):
                    return True
                board[row_index][col_index] = tmp_val
            return False

        for index1 in range(row_len):
            for index2 in range(col_len):
                if isElemOk(index1, index2, word):
                    return True

        return False

```