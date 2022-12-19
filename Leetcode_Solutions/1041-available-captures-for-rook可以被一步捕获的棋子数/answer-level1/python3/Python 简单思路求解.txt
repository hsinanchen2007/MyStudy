### 解题思路
思路很简单：先找到这个车的位置，然后从这个位置出发，依次向上，向下，向左，向右走一遍，第一次遇见卒就+1，然后退出，第一次遇见像就直接退出。关于坐标：其实可以记录一下上面一个卒，就会发现，是列数没变，行数变了。很容易写出代码
比较耗时的就是两个for循环。

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        ##思路：
        ## 1、先找到白色的车的位置，
        ## 2、然后看白色车的位置的上下左右这一行中有没有黑色卒的棋子，同时没有白色大象的棋子，或者白色大象的棋子在黑色卒的棋子的后面，就可以找到
        ##整个盘的大小固定是8*8
        nums = 0  ##记录能够取到的数目
        ##1、找到白色车的位置
        for i in range(8):
            for j in range(8):
                if board[i][j]=="R":
                    m = i
                    n = j
                    break

        ##2、判断这一行或者列中存在黑色的棋子（p），同时没有白色大象(B)
        ##向上找：
        for i in range(m,0,-1):
            if board[i][n]=="p":
                nums+=1
                break
            if board[i][n]=="B":
                break
        ##向下找:
        for i in range(m,8):
            if board[i][n]=="p":
                nums+=1
                break
            if board[i][n]=="B":
                break
        ##向左找：
        for  i in range(n,0,-1):
            if board[m][i]=="p":
                nums+=1
                break
            if board[m][i]=="B":
                break
        ##向右找：
        for i in range(n,8):
            if board[m][i]=="p":
                nums+=1
                break
            if board[m][i]=="B":
                break
        return nums
            


```