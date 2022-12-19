C语言，递归+回溯


```c
int* pRecord=NULL;
int sum = 0;

int match_cal(int row, int col, int n)
{
    int i = 0;
    int j = 0;
    for (i=0; i<row; i++)
    {
        for (j=0; j<n; j++)
        {
            if(*(pRecord+i*n+j) == 1)
            {
                if (j == col)
                    return 0;
                    
                if (abs(row - i) == abs(col - j))
                {
                    return 0;
                }               
            }           
        }
        
    }

    return 1;
}

void cal_sum(int row, int n)
{
    int col=0;
    int ret=0;
    
    if(row >= n)
    {
        sum++;
        return;
    }
    
    for(col = 0; col < n; col++)
    {
        ret = match_cal(row,col,n);
        if(1 == ret)
        {
            *(pRecord+row*n+col) = 1;
            cal_sum(row+1,n);
            *(pRecord+row*n+col) = 0;
        }
    
    }
    
    return;

}

int totalNQueens(int n){
    int col = 0;
    int row = 0;
    int ret = 0;
    int first = 0;
    int count = 0;
    int i =0;
    sum = 0;
    

    if (n == 1)
    {
        return 1;
    }

    pRecord = (int*)malloc(sizeof(int)*n*n);
    if(NULL == pRecord)
    {
        return 0;
    }
    memset(pRecord,0,n*n*sizeof(int));
    
    cal_sum(0, n);

    free(pRecord);
    return sum;
}
```