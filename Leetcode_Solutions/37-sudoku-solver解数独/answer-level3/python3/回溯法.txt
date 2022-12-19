# 思路
1、初始数独如下：
![2019-10-15_094449.png](https://pic.leetcode-cn.com/003659fa879c44cf922799ac9fbec726624dd6634a9f60b879e660f2b60ea0c1-2019-10-15_094449.png)
2、从左到右从上到下来填充空白：
    用什么填充：1-9个数字，for循环挨个来试
    不能填充的时候：回溯到上一个填充的位置，用for循环换一个值，看能否继续往下走。
3、例子：
![image.png](https://pic.leetcode-cn.com/bc12af914f89134e5931bf0ebe030ab4a2a43bc6a9eb07cca35aa6da1b3ff8be-image.png)
如上图所示，back_function利用for循环给board[0][2]填充了1, 接着递归back_function给board[0][3]填充2，再递归一直到board[0][8]位置不能填充任何值了，所以board[0][7]所调用的back_function不做任何事情就返回了，然后board[0][7]处的back_function移除board[0][7]此处的值，用for循环开始试下一个值，看能否继续往下填充，如果board[0][7]处的1-9个数字都试过了不能继续走下去，则回溯到board[0][6]，以此类推。
注意：board中的任意一个需要填充的位置，如果1-9个数字都不能填充时，函数就会回溯到它的上一个位置，如果能填充就会一直往下填充，直到结束得到数独解。


# 代码

```
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def count_number(row, col, d):  # 统计数字
            rows[row][d] += 1
            columns[col][d] += 1
            boxs[box_index(row, col)][d] += 1
        def place_number(row, col, d):  # 填充数字
            board[row][col] = str(d)
        def could_place(row, col, d):  # 是否能用d填充'.'
            return not (d in rows[row] or d in columns[col] or d in boxs[box_index(row, col)])
        
        def place_nextNumber(row, col):  # 填充当前位置的下一个位置
            if row == col == N-1:
                nonlocal solution_find
                solution_find = True
            elif col == N-1:
                back_function(row+1, 0)
            else:
                back_function(row, col+1)
        def remove_number(row, col, d):  # 移除当前位置的填充值
            del rows[row][d]
            del columns[col][d]
            del boxs[box_index(row, col)][d]
            board[row][col] = '.'
                
        def back_function(row=0, col=0):  # 回溯大法
            if board[row][col] == '.':
                for d in range(1, 10):
                    if could_place(row, col, d):
                        count_number(row, col, d)
                        place_number(row, col, d)
                        place_nextNumber(row, col)
                        if not solution_find:  # 是否找到数独解
                            remove_number(row, col, d)           
            else:
                place_nextNumber(row, col)
                
            
        
        N = 9 # 9*9宫格
        from collections import defaultdict  # key不存在时不会抛出异常，返回为None
        rows  = [defaultdict(int) for _ in range(N)]
        columns = [defaultdict(int) for _ in range(N)]
        boxs = [defaultdict(int) for _ in range(N)]
        box_index = lambda x, y : x // 3 * 3 + y // 3
        
        # 根据board填充rows、columns和boxs
        for i in range(N):
            for j in range(N):
                if board[i][j] != '.':
                    count_number(i,j, int(board[i][j]))
        # 是否能找到数独的解
        solution_find = False
        # 回溯函数
        back_function()
```
