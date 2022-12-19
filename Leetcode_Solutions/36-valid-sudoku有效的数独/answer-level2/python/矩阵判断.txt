### 解题思路
直接判断三种内容是否出现重复样例即可

### 代码

```python3
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        hash1, hash2, hash3 = [[] for i in range(9)], [[] for i in range(9)], [[] for i in range(9)]
        for i in range(9):
            for j in range(9):
                if board[i][j] not in hash1[i] and board[i][j] != '.':
                    hash1[i].append(board[i][j])
                elif board[i][j] in hash1[i]:
                    return False
                if board[i][j] not in hash2[j] and board[i][j] != '.':
                    hash2[j].append(board[i][j])
                elif board[i][j] in hash2[j]:
                    return False
                temp = i // 3 + (j // 3) * 3
                if board[i][j] not in hash3[temp] and board[i][j] != '.':
                    hash3[temp].append(board[i][j])
                elif board[i][j] in hash3[temp]:
                    return False
        return True


```