### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        result = [False]
        n = list(word)
        def back(word,result,path,i,j,index):
            if len(path) == len(word):
                result[0] = True
                return
            if result[0] == False and index < len(n):
                if board[i][j] == word[index] and [i,j] not in path:
                    tem = path[:]
                    tem.append([i,j])
                    if i + 1 < len(board) and index + 1 < len(n):
                        if board[i + 1][j] == n[index + 1]:
                            back(word,result,tem,i + 1,j,index + 1)
                    if i > 0 and index + 1 < len(n):
                        if board[i - 1][j] == n[index + 1]:
                            back(word,result,tem,i - 1,j,index + 1)
                    if j + 1 < len(board[0]) and index + 1 < len(n):
                        if board[i][j + 1] == n[index + 1]:
                            back(word,result,tem,i,j + 1,index + 1)
                    if j > 0 and index + 1 < len(n):
                        if board[i][j - 1] == n[index + 1]:
                            back(word,result,tem,i,j - 1,index + 1)
                    if index == len(n) - 1:
                        back(word,result,tem,i,j,index + 1)
        for i in range(len(board)):
            for j in range(len(board[0])):
                back(n,result,[],i,j,0)
                if result[0] == True:
                    break
            if result[0] == True:
                    break
        return result[0]
```