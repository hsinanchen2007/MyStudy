### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   public int numRookCaptures(char[][] board) {
        int x =0;
        int y =0;
        for(int i = 0;i < board.length;i++)
        {
            for(int j = 0;j < board[0].length;j++)
            {
                if(board[i][j] == 'R')
                {
                    x = i;
                    y = j;
                }
            }
        }

        int sum = 0;
        int i = x;
        int j = y+1;
        while(j < board[0].length)
        {
            if(board[i][j] == 'B')
            {
                break;
            }
            if(board[i][j] == 'p')
            {
                sum+=1;
                break;
            }
            j++;
        }

        j = y-1;
        while(j >= 0)
        {
            if(board[i][j] == 'B')
            {
                break;
            }
            if(board[i][j] == 'p')
            {
                sum+=1;
                break;
            }
            j--;
        }

        i = x-1;
        j = y;


        while(i >= 0)
        {
            if(board[i][j] == 'B')
            {
                break;
            }
            if(board[i][j] == 'p')
            {
                sum+=1;
                break;
            }
            i--;
        }

        i = x+1;

        while(i < board.length)
        {
            if(board[i][j] == 'B')
            {
                break;
            }
            if(board[i][j] == 'p')
            {
                sum+=1;
                break;
            }
            i++;
        }

        return sum;


    }
}
```