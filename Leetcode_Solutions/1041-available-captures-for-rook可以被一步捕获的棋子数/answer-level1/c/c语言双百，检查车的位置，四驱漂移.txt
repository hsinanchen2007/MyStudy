### 解题思路
一个for循环应该比暴力的四个for要强一丢丢吧，哈哈
![image.png](https://pic.leetcode-cn.com/c8fcc8a507a7d98c32571c38b4636782d2ff51281804190012d1a7940b4742bc-image.png)

### 代码

```c
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int x,y;
    for(int i=0;i<boardSize;i++)
    {
        for(int j=0;j<*boardColSize;j++)
        {
            if(board[i][j]=='R')
            {
                x=i;
                y=j;
                break;
            }
        }
    }
    int left=y,right=y,up=x,down=x;
    int sum=0;
    for(int i=1;i<5;i++)
    {
        if(left-1>=0&&board[x][left-1]!='B')
        {
            --left;
            if(board[x][left]=='p')
            {
                sum++;
                left=-1;
            }
        }
        if(right+1<*boardColSize&&board[x][right+1]!='B')
        {
            ++right;
            if(board[x][right]=='p')
            {
                sum++;
                right=*boardColSize;
            }
        }
        if(up-1>=0&&board[up-1][y]!='B')
        {
            --up;
            if(board[up][y]=='p')
            {
                sum++;
                up=-1;
            }
        }
        if(down+1<boardSize&&board[down+1][y]!='B')
        {
            ++down;
            if(board[down][y]=='p')
            {
                sum++;
                down=boardSize;
            }
        }
    }
    return sum;
}
```