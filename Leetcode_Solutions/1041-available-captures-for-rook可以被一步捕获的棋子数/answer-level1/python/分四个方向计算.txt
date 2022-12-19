### 解题思路
首先遍历全部网格，找到R(白色车),然后分上下左右四个方向判断，首先判断是否到达边缘，如果是则该方向
无法捕获卒，否则，判断该位置是空(.)/白色的象(B)/黑色的卒，对应操作:朝该方向下一个位置移动/该方向
无法捕获卒/卒数量加1，结束该方向判断。判断完四个方向，返回组数量。

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        tem_x = 0
        tem_y = 0
        Sum1 = 0
        for i in range(8):
            for j in range(8):
                if(board[i][j]=='R'):
                    tem_x = i
                    tem_y = j
        tem_x1 = tem_x
        tem_y1 = tem_y
        while(tem_x1-1>=0):
            if(board[tem_x1-1][tem_y1]=='B'):
                break
            elif(board[tem_x1-1][tem_y1]=='.'):
                tem_x1 -=1
            else:
                Sum1 +=1
                break
        tem_x1 = tem_x
        tem_y1 = tem_y
        while(tem_x1+1<=7):
            if(board[tem_x1+1][tem_y1]=='B'):
                break
            elif(board[tem_x1+1][tem_y1]=='.'):
                tem_x1 +=1
            else:
                Sum1 +=1
                break
        tem_x1 = tem_x
        tem_y1 = tem_y
        while(tem_y1-1>=0):
            if(board[tem_x1][tem_y1-1]=='B'):
                break
            elif(board[tem_x1][tem_y1-1]=='.'):
                tem_y1 -=1
            else:
                Sum1 +=1
                break
        tem_x1 = tem_x
        tem_y1 = tem_y
        while(tem_y1+1<=7):
            if(board[tem_x1][tem_y1+1]=='B'):
                break
            elif(board[tem_x1][tem_y1+1]=='.'):
                tem_y1 +=1
            else:
                Sum1 +=1
                break
        return Sum1


                
```