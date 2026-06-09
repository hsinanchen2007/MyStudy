使用回溯法进行求解。
```
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        # 进行搜索与回溯，递归判断每一个位置的附近是否能被搜索（上下左右是否越界，是否被使用过，是否和接下来需要匹配的word中元素吻合）。used数组用于辅助记录，哪些位置的元素已经被使用过
        used = [[0] * len(board[0]) for i in range(len(board))]

        def find(board, word, position, ci, cj):  # board：棋盘数组。Word：目标字符串。position：word字符串当前需要进行匹配的位置。[ci][cj]：当前搜索过程在board棋盘中的位置

            if position == len(word):  # word数组全部匹配成功，即返回True
                return True

            if cj > 0 and used[ci][cj-1] == 0 and board[ci][cj-1] == word[position]:
                used[ci][cj-1] = 1
                flag = find(board, word, position+1, ci, cj-1)  # 从左方继续搜索
                if flag:
                    return True
                used[ci][cj-1] = 0  # 回溯

            if ci > 0 and used[ci-1][cj] == 0 and board[ci-1][cj] == word[position]:
                used[ci-1][cj] = 1
                flag = find(board, word, position+1, ci-1, cj)  # 从上方继续搜索
                if flag:
                    return True
                used[ci-1][cj] = 0  # 回溯

            if cj < len(board[0])-1 and used[ci][cj+1] == 0 and board[ci][cj+1] == word[position]:
                used[ci][cj+1] = 1
                flag = find(board, word, position+1, ci, cj+1)  # 从右方继续搜索
                if flag:
                    return True
                used[ci][cj+1] = 0  # 回溯

            if ci < len(board)-1 and used[ci+1][cj] == 0 and board[ci+1][cj] == word[position]:
                used[ci+1][cj] = 1
                flag = find(board, word, position+1, ci+1, cj)  # 从下方继续搜索
                if flag:
                    return True
                used[ci+1][cj] = 0  # 回溯

            return False

        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == word[0]:  # word头元素匹配成功，开始进行搜索
                    used[i][j] = 1
                    flag = find(board, word, 1, i, j)
                    used[i][j] = 0
                    if flag:
                        return True

        return False

```
