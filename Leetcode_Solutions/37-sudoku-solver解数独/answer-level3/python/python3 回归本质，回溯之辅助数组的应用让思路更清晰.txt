### 解题思路
此处撰写解题思路
两份代码都不是自己写的，后者只是自己改编成python的，前者也是之前copy过来的，用于学习记录。都有作者的连接记录下面，可自行前往阅读。
[第一篇代码原文](https://leetcode-cn.com/problems/sudoku-solver/solution/pythondi-gui-hui-su-xiao-lu-yi-ban-dan-tong-su-yi-/)
[第二篇代码原文](https://leetcode-cn.com/problems/sudoku-solver/solution/zi-cong-wo-xue-hui-liao-hui-su-suan-fa-zhong-yu-hu/)

先找到需要填充的索引位置，用列表locs记录，然后三个字典记录每列，每行，每个方块选择了哪些数字，
之后回溯的时候，只有在每行每列，每个方块都不出现的数字才可以进行回溯选择，
选择之后，要在字典更新已经选择了这个数字，才可以接着进行下一步的回溯。
如果没找到，就要撤回去，不选择，也就是要在3个字典里面修改回来

每次回溯都要选择一个列表记录的索引位置，pop出来一个索引元素，如果回溯不成功，就要回到原始阶段，append回去，同时board的修改也是修改回去。
第一个思路是参考的这位[道友](https://leetcode-cn.com/problems/sudoku-solver/solution/pythondi-gui-hui-su-xiao-lu-yi-ban-dan-tong-su-yi-/)的


之前自己想的是找到每个'.'可以选择的数字，然后回溯，但是这样，很浪费时间，而且，前者选择了， 后者的就要受到影响，不如这个3个字典记录来得方便。

之后还看了[labuladong](https://leetcode-cn.com/problems/sudoku-solver/solution/zi-cong-wo-xue-hui-liao-hui-su-suan-fa-zhong-yu-hu/)大哥的文章，
改编了一个python版本的代码，很简洁，isvalid用的很巧妙，和这里的三个字典记录一个意思，只是时间上差了点，
改编的是从0，0开始的，81个都有进入，在backtrace函数里面去掉了那个对预设数字的回溯，直接进行下一个，但是这样的整体时间效率确实比三个字典的空间换时间的差。
都有借鉴的地方，东哥的一个基本思路，选择就是1-9，去除无效的，去除预设的，最主要的是backtrace需要返回True，来判断是否成功，回溯的base case是什么？
三个字典的辅助的basecase是locs列表为空；
改编的basecase 是j==9，说前面都正常，回溯递归完毕了。

都有值得学习的地方，也想到了一部分内容，但是就是没写出来。。。之前的那些排列组合什么的还是过于简单了，写的得心应手，
在这上面栽了坑，辅助数组的应用不够得心应手，也完全没想到。在这记录一下，看看日后可不可以子集重写一遍出来，哈哈

### 代码

```python3
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def getLocs(board):#初始化，获取需要填充的位置，记录为一个栈
            locs = []
            for row in range(9):
                for col in range(9):
                    if board[row][col] == '.':
                        locs.append((row, col))
            return locs

        def getMaps(board):#定义三个字典，跟踪9行、9列和9块的已填充数字，采用数据结构为defaultdict
            from collections import defaultdict as dd
            rowMap = [dd(int) for _ in range(9)]
            colMap = [dd(int) for _ in range(9)]
            blockMap = [dd(int) for _ in range(9)]
            for row in range(9):
                for col in range(9):
                    if board[row][col] != '.':
                        num = int(board[row][col])
                        rowMap[row][num] += 1
                        colMap[col][num] += 1
                        bolckIndex = row//3*3+col//3
                        blockMap[bolckIndex][num] += 1
            return rowMap, colMap, blockMap

        def fillBoard(board, locs):#递归填充剩余的数独空位置
            if not locs:
                return True
            row, col = locs.pop()#弹出一个待填充位置
            bolckIndex = row//3*3+col//3
            found = False
            for num in range(1, 10):
                if found:
                    break
                if not rowMap[row][num] and not colMap[col][num] and not blockMap[bolckIndex][num]:
                    ##如果当前行、当前列和当前块均不存在该数字，则将数字更新到相应行、列、块，并尝试填充
                    rowMap[row][num] = 1
                    colMap[col][num] = 1
                    blockMap[bolckIndex][num] = 1
                    board[row][col] = str(num)
                    found = fillBoard(board, locs)#递归到下一层填充
                    rowMap[row][num] = 0##状态回溯，将填充的位置清空
                    colMap[col][num] = 0
                    blockMap[bolckIndex][num] = 0
            if not found:##如果本轮都无法求解，则回溯到初始状态，继续从前面再填充
                locs.append((row, col))
                board[row][col] = '.'
            return found

        rowMap, colMap, blockMap = getMaps(board)
        locs = getLocs(board)
        fillBoard(board, locs)


```


```python3
LABULADONG  改编的python版本的代码
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        def backtrack(board, i, j) :
            if j == 9:
                #  穷举到最后一列的话就换到下一行重新开始。
                return backtrack(board, i + 1, 0)
            
            if i == 9:
                #  找到一个可行解，触发 base case
                return True
            
            if board[i][j] != '.':
                #  如果有预设数字，不用我们穷举
                return backtrack(board, i, j + 1)
            
            for ch in '123456789':
                #  如果遇到不合法的数字，就跳过
                if not isValid(board, i, j, ch):
                    continue
                
                board[i][j] = ch
                #  如果找到一个可行解，立即结束
                if backtrack(board, i, j + 1):
                    return True
                
                board[i][j] = '.'
            
            #  穷举完 1~9，依然没有找到可行解，此路不通
            return False

        def isValid(board, r, c, n) :
            for i in range(9):
                #  判断行是否存在重复
                if board[r][i] == n: return False
                #  判断列是否存在重复
                if board[i][c] == n: return False
                #  判断 3 x 3 方框是否存在重复
                if board[(r//3)*3 + i//3][(c//3)*3 + i%3] == n:
                    return False
            return True 
        backtrack(board,0,0)
```