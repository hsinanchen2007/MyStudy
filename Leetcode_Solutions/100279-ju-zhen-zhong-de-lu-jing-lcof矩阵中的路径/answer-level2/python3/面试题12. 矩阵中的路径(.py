### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        # 回溯法,跟递归类似
        # 函数功能:输入i/j/k,以i/j开头的字符,是否与word[k]开头的字符匹配
        def dfs(i,j,k):
            # 终止条件:
            if not 0<=i<=len(board)-1 or not 0<=j<=len(board[0])-1 or board[i][j] != word[k]:
                return False
            if k == len(word) - 1:
                return True
            
            # 将遍历过的元素做标记
            tmp,board[i][j] = board[i][j],'/'
            # 递归出结果
            res = dfs(i+1,j,k+1) or dfs(i-1,j,k+1) or dfs(i,j+1,k+1) or dfs(i,j-1,k+1)
            board[i][j] = tmp
            return res
        
        for i in range(len(board)):
            for j in range(len(board[0])):
                if dfs(i,j,0):
                    return True
        return False

```