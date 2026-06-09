### 解题思路
在数独I的基础上，采用递归+回溯的方式进行探测求解，用三个字典列表对填充数字进行标记。处理好尝试失败后的状态回溯即可。
因为最多也就只有81个空位，所以递归深度不会溢出。

### 执行结果
![image.png](https://pic.leetcode-cn.com/1fbc4b4c94840e5abe656d02f8b30155ae9ae8651f00408e38376f5db114e8cf-image.png)

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
                        bolckIndex = int(row/3)*3+int(col/3)
                        blockMap[bolckIndex][num] += 1
            return rowMap, colMap, blockMap

        def fillBoard(board, locs):#递归填充剩余的数独空位置
            if not locs:
                return True
            row, col = locs.pop()#弹出一个待填充位置
            bolckIndex = int(row/3)*3+int(col/3)
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
最后，低调推荐个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)
