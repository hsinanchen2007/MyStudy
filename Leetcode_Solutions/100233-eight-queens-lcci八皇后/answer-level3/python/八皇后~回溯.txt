### 解题思路
对于回溯的理解可以看看这篇[labuladong对回溯算法的详解](https://leetcode-cn.com/problems/n-queens/solution/hui-su-suan-fa-xiang-jie-by-labuladong/)

回溯的框架
```
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择
```
回溯在我的理解就是，你需要吧问题转化成树的问题，然后进行深度遍历求路径（相信DFS大家都不陌生）
下面我们用4-皇后问题来简化的建树

![image.png](https://pic.leetcode-cn.com/564dad6a69328128705cc535735f295f91e2f3419bfa64b0691c24f582ede315-image.png)

建议大家自己手动模拟一遍

那么对于剪枝的部分，我们都需要减掉哪些情况呢？看下图

![image.png](https://pic.leetcode-cn.com/1456b8fdb0ef6819ca1737ae10831aecc3ef21b2d87bd22edb4d6015694f9158-image.png)
红色部分代表我们在第三行遍历到的一个格子，基于前面两行去判断这个点可以不可以是皇后如果可以是的话，那么基于这个格子进行进行下去
`backtrack(board, row+1, res)`




### 代码

```python3
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        
        board = [["."] * n for _ in range(n)] # 初始化，因为str类型不能直接赋值，这样在做选择的时候会报错
        def convert(board):
            formal_lst = []
            for each in board:
                temp = ''.join(each)
                formal_lst.append(temp)
            return formal_lst

        res = []
        def isValid(board, row, col):
            # 列是否有皇后
            for i in range(row):
                if board[i][col] == 'Q':
                    return False
            i, j = row-1, col+1
            while i >= 0 and j < n: # 左上角
                if board[i][j] == 'Q':
                    return False
                else:
                    i -= 1
                    j +=1
            i, j = row-1, col-1
            while i >= 0 and j >= 0: # 右上角
                if board[i][j] == 'Q':
                    return False
                else:
                    i -= 1
                    j -= 1
            return True       

        def backtrack(board, row, res):
            if row == len(board):
                res.append(convert(board))
                return 
            for i in range(n):
                if isValid(board, row, i) == False:
                    continue
                else:
                    board[row][i] = 'Q' # 做选择
                    backtrack(board, row + 1, res) 
                    board[row][i] = '.' # 选择好回撤，便于下一次选择
                    
        backtrack(board, 0,res)

        return res
```