### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
int [] neb = {0,1,-1};

for(int i = 0;i < board.length;i++)
{
for(int j = 0;j < board[0].length;j++)
{
int temp = board[i][j];
for(int z = 0;z < 3;z++)
{
for(int y = 0;y < 3;y++)
{
if(neb[z] != 0 || neb[y] != 0)
{
int row = i+neb[z];
int col = j+neb[y];

if(row>=0 && row<board.length && col>=0 && col<board[0].length && Math.abs(board[row][col])==1)
{
    board[i][j] += 1;
}
}
}
}
if(temp == 1)
{
 board[i][j] -= 1;
}
   if(temp == 0 && board[i][j] ==3)
   {
 board[i][j] = 2;
   }

 else if(temp == 1 && board[i][j] <2)
   {
 board[i][j] = -1;
   }
   else  if(temp == 1 && board[i][j] ==2 ||temp == 1 && board[i][j] ==3 )
   {
 board[i][j] = 1;
   }
  else   if(temp == 1 && board[i][j] >3)
   {
 board[i][j] = -1;
   }
  else
                    {
                        board[i][j] = temp;
                    }
}

}
   // 遍历 board 得到一次更新后的状态
        for (int row = 0; row < board.length; row++) {
            for (int col = 0; col < board[0].length; col++) {
                if (board[row][col] > 0) {
                    board[row][col] = 1;
                } else {
                    board[row][col] = 0;
                }
            }
        }
    }
}
```