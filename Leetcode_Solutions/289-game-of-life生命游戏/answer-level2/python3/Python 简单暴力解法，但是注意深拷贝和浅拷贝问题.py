### 解题思路
**本题用深拷贝！！深拷贝！！深拷贝！！！**
首先：区分一下：直接赋值、浅拷贝、深拷贝
**直接复制：指向的是引用，还是同一个对象**
```
a= [1,2,3,4]
b = a  ##直接赋值
a.append(5)

print(a)   ##a = [1,2,3,4,5]
print(b)   ##b = [1,2,3,4,5]  因为指向的是同一个对象，所以只要对象改变，都会改变
```
**浅拷贝：是两个独立的对象，但是还是指向同一个对象**
```
a = [1,2,3,4]
b = a.copy()
a.append(5)

print(a) ## a = [1,2,3,4,5]
print(b) ## b = [1,2,3,4,5] 因为还是指向的同一个对象，所以只要对象改变，都会改变
```
**深拷贝：真正的完全拷贝了值，是真正的两个独立的个体，没有任何关系，需要import copy**
```
import copy
a = [1,2,3,4]
b = copy.deepcopy(a)
a.append(5)

print(a)  ## a = [1,2,3,4,5]
print(b)  ## b = [1,2,3,4]  ##因为真正独立了，所以a改变并不会影响自己
```
详情请戳：[https://www.runoob.com/w3cnote/python-understanding-dict-copy-shallow-or-deep.html]()
显然，在这里，我们用**深拷贝**，大家不能用错了，所以：
1、第一种方式
```
import copy
board_copy= copy.deepcopy(board)
```
2、第二种方式
```
board_copy = [[board[rw][cl] for cl in range(col)] for rw in range(row)]
```
PS：好像说的有点远了，整体题目很简单。还需要注意的是，边界的值是不需要判断的，直接略过，因为边界的值是没有八个方向的。



### 代码

```python3

class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # board_copy = board   ##这种方式不对
        row = len(board)    ##行
        col = len(board[0]) ##列
        board_copy = [[board[rw][cl] for cl in range(col)] for rw in range(row)]
        ##定义八个方向:上，下，左，右，左上，左下，右上，右下
        direction = [[-1,0],[1,0],[0,-1],[0,1],[-1,-1],[1,-1],[-1,1],[1,1]]
        for i in range(row):
            for j in range(col):
                nums = 0 ##记录八个方向上的活细胞或者死细胞的个数 
                for k in range(8):
                    dx = direction[k][0]+i
                    dy = direction[k][1]+j
                    if dx>=0 and dx<row and dy>=0 and dy<col and board_copy[dx][dy]==1:
                        nums+=1

                if board_copy[i][j]==1:  
                    if nums<2:
                        board[i][j] = 0
                    if nums>3:
                        board[i][j] = 0
                    if nums==2 or nums==3:
                        board[i][j] = 1
                else:
                    if nums==3:
                        board[i][j] = 1

```