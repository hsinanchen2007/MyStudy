### 解题思路
本质上还是dfs回溯算法，只是可以提前进行剪枝。
回溯算法需要注意，要标记每次已经使用过的点，下次就不要再次使用了。
思路就是首先找到一个起点，然后进入dfs循环，判断这个路能不能走的通。如果走通就返回True 否则返回False

### 代码

```python
class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        #print(queue)
        
        def dfs(r, l, n,mark):
            if n == len(word):
                return True
            # 向上尝试
            if r>0 and board[r-1][l]==word[n] and mark[r-1][l]==0:
                mark[r-1][l] = 1 ## ！！标记！！
                if dfs(r-1, l, n+1,mark):
                    return True
                mark[r-1][l] = 0 ## ！！回退标记！！
            ## 向下
            if r<h-1 and board[r+1][l] == word[n] and mark[r+1][l]==0:
                mark[r+1][l] = 1
                if dfs(r+1, l, n+1,mark):
                    return True
                mark[r+1][l] = 0
            ##向左
            if l>0 and board[r][l-1]==word[n] and mark[r][l-1]==0:
                mark[r][l-1] = 1
                if dfs(r, l-1, n+1,mark):
                    return True
                mark[r][l-1] = 0
            ## 向右
            if l<w-1 and board[r][l+1] == word[n] and mark[r][l+1]==0:
                mark[r][l+1] = 1
                if dfs(r, l+1, n+1, mark):
                    return True
                mark[r][l+1] = 0
            return False 
        

        queue = []
        h = len(board)
        w = len(board[0])
        ## 建立初始状态
        mark = [[0 for i in range(w)]for j in range(h)]
        ##查找起始点
        for i in range(h):
            for j in range(w):
                if board[i][j] == word[0]:
                    mark[i][j] = 1
                    if dfs(i,j, 1,mark):
                        return True
                    mark[i][j] =0
        return False

```