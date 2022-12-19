### 解题思路
思路就是在原数组上操作，状态变化了就使用其他数字标记一下就好了。对于每个下标只循环指定的次数即可，算出循环的最大值和最小值就ok； 

![image.png](https://pic.leetcode-cn.com/0c21fd1adf9c483bd6679514a868275dd19cd5b44fade5bbde1b15c1563ffe26-image.png)


### 代码

```c
#define DEAD_TO_LIVE 2
#define LIVE_TO_DEAD 4

void CalStatus(int** board, int Curboard, int CurColSize, int MaxBoard, int MaxColSize)
{
    int CurStatus = board[Curboard][CurColSize];
    int NewStatus;
    int countTmp;   
    int count = 0;
    int leftMin = 0;
    int rightMin = 0;
    int leftMax = 0;
    int rightMax = 0;
    int i,j;

    leftMax  = (MaxBoard == Curboard)?Curboard:(Curboard+1);
    rightMax = (MaxColSize == CurColSize)?CurColSize:(CurColSize+1);

    leftMin  = (0 == Curboard)?Curboard:(Curboard-1);
    rightMin = (0 == CurColSize)?CurColSize:(CurColSize-1);

    for(i=leftMin; i<=leftMax; i++)
    {
        for(j=rightMin; j<=rightMax; j++)
        {
            countTmp = board[i][j];
            if(DEAD_TO_LIVE == countTmp)
            {
                countTmp = 0;
            }
            else if(LIVE_TO_DEAD == countTmp)
            {
                countTmp = 1;
            }
            count += countTmp;
        }
    }

    count = count - board[Curboard][CurColSize];

    NewStatus = CurStatus;

    if((0 == CurStatus) && (3 == count))
    {
        NewStatus = DEAD_TO_LIVE;
    }
    
    if(1 == CurStatus)
    {
        if((count > 3) || (count < 2))
        {
            NewStatus = LIVE_TO_DEAD;
        }
    }

    board[Curboard][CurColSize] = NewStatus;
}

void gameOfLife(int** board, int boardSize, int* boardColSize){
    int i,j;
    for(i=0; i<boardSize; i++)
    {
        for(j=0; j<boardColSize[0]; j++)
        {
            CalStatus(board, i, j, boardSize-1, boardColSize[0]-1);
        }
    }

    for(i=0; i<boardSize; i++)
    {
        for(j=0; j<boardColSize[0]; j++)
        {
            if(DEAD_TO_LIVE == board[i][j])
            {
                board[i][j] = 1;
            }
            else if(LIVE_TO_DEAD == board[i][j])
            {
                board[i][j] = 0;
            }
        }
    }

    return 0;

}
```