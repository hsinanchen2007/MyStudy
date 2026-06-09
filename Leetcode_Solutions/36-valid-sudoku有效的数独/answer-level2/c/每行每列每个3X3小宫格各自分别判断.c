### 解题思路
此处撰写解题思路

### 代码

```c
bool judge(char *nums, int numssize)//判断一个字符数组中是否有重复元素
{
    if(numssize==0 || numssize==1)
    {
        return true;
    }
    else
    {
        for(int i=0;i<numssize-1;i++)
    {
        for(int j=i+1;j<numssize;j++)
        {
            if(nums[i]==nums[j]) return false;
        }
    }
        return true;
    }
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    char temp[10];
    for(int i=0,k=0;i<9;i++,k=0)//判断每一行是否有重复的元素,i是行的指针,j是列的指针,k是临时数组的指针
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]!='.') temp[k++]=board[i][j];                          
        }
        if(judge(temp,k)==false) return false; 
     
        
    }
    

    for(int i=0,k=0;i<9;i++,k=0)//判断每一列是否有重复的元素,i是列的指针,j是行的指针,k是临时数组的指针
    {
        for(int j=0;j<9;j++)
        {
            if(board[j][i]!='.') temp[k++]=board[j][i];                          
        }
        if(judge(temp,k)==false) return false; 
          
    }

    for(int k=0,m=0;m<1;m++)//判断3X3宫1
    {
        for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]!='.') temp[k++]=board[i][j];                          
        }
    }
    if(judge(temp,k)==false) return false; 
    }

    for(int k=0,m=0;m<1;m++)//判断3X3宫2
    {
        for(int i=0;i<3;i++)
    {
        for(int j=3;j<6;j++)
        {
            if(board[i][j]!='.') temp[k++]=board[i][j];                          
        }
    }
    if(judge(temp,k)==false) return false; 
    }

    for(int k=0,m=0;m<1;m++)//判断3X3宫3
    {
        for(int i=0;i<3;i++)
    {
        for(int j=6;j<9;j++)
        {
            if(board[i][j]!='.') temp[k++]=board[i][j];                          
        }
    }
    if(judge(temp,k)==false) return false; 
    }

    for(int k=0,m=0;m<1;m++)//判断3X3宫4
    {
        for(int i=3;i<6;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]!='.') temp[k++]=board[i][j];                          
        }
    }
    if(judge(temp,k)==false) return false; 
    }

    for(int k=0,m=0;m<1;m++)//判断3X3宫5
    {
        for(int i=3;i<6;i++)
    {
        for(int j=3;j<6;j++)
        {
            if(board[i][j]!='.') temp[k++]=board[i][j];                          
        }
    }
    if(judge(temp,k)==false) return false; 
    }

    for(int k=0,m=0;m<1;m++)//判断3X3宫6
    {
        for(int i=3;i<6;i++)
    {
        for(int j=6;j<9;j++)
        {
            if(board[i][j]!='.') temp[k++]=board[i][j];                          
        }
    }
    if(judge(temp,k)==false) return false; 
    }

    for(int k=0,m=0;m<1;m++)//判断3X3宫7
    {
        for(int i=6;i<9;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]!='.') temp[k++]=board[i][j];                          
        }
    }
    if(judge(temp,k)==false) return false; 
    }

    for(int k=0,m=0;m<1;m++)//判断3X3宫8
    {
        for(int i=6;i<9;i++)
    {
        for(int j=3;j<6;j++)
        {
            if(board[i][j]!='.') temp[k++]=board[i][j];                          
        }
    }
    if(judge(temp,k)==false) return false; 
    }

    for(int k=0,m=0;m<1;m++)//判断3X3宫9
    {
        for(int i=6;i<9;i++)
    {
        for(int j=6;j<9;j++)
        {
            if(board[i][j]!='.') temp[k++]=board[i][j];                          
        }
    }
    if(judge(temp,k)==false) return false; 
    }

    return true;

}
```