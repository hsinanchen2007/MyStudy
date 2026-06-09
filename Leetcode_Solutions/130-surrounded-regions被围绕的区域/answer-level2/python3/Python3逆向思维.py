### 解题思路
1、找到边界上的O和他们邻接的O(使用递归)
2、将这些O标记为Y
3、将其他O置为X
4、将Y复原为O

### 代码

```python3
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if len(board)==0:
            return []
        length=len(board)
        width=len(board[0])
        #找边界上的O
        def get_O_position():
            for i in range(width):
                if board[0][i]=='O':
                    return 0,i
                if board[length-1][i]=='O':
                    return length-1,i
            for i in range(1,length-1):
                if board[i][0]=='O':
                    return i,0
                if board[i][width-1]=='O':
                    return i,width-1
            return -1,-1
        #找边界和相邻的O，并改成Y
        def O_to_Y(x,y):
            board[x][y]='Y'
            if x>0 and board[x-1][y]=='O':
                O_to_Y(x-1,y)
            if y>0 and board[x][y-1]=='O':
                O_to_Y(x,y-1)
            if x<length-1 and board[x+1][y]=='O':
                O_to_Y(x+1,y)
            if y<width-1 and board[x][y+1]=='O':
                O_to_Y(x,y+1)

        x,y=get_O_position()
        while x!=-1 and y!=-1:
            O_to_Y(x,y)
            x,y=get_O_position()
        #把其他O改成X
        for i in range(length):
            for j in range(width):
                if board[i][j]=='O':
                    board[i][j]='X'
        #把Y改回O
        for i in range(length):
            for j in range(width):
                if board[i][j]=='Y':
                    board[i][j]='O'

            



```