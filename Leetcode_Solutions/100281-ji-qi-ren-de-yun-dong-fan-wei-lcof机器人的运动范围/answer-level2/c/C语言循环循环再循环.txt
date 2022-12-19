### 解题思路
起始位置开始记录当前是否能到达。能达到为1.其余的都为0；
数组a不初始化的话，提交就报错，不知道为啥

### 代码

```c
int Count(int count)
{
    int count_result=0;
    int temp;

    if(count < 10)
    {
        count_result = count;
    }
    else
    {
        temp = count;
        while(temp > 0)
        {
            count_result += temp%10;
            temp = temp / 10; 
        }
    }
    return count_result;
    
}

int movingCount(int m, int n, int k){
    int i,j;
    int tempi,tempj;
    int a[m][n] ;
    int total = 0;
    
    if(0==m || 0==n)
    {
        return 0;
    }

    for(i=0; i<m; i++)
    {
        for(j=0; j<n ; j++)
        {
            a[i][j] = 0;
        }
    }
    for(i=0; i<m; i++)
    {
        for(j=0; j<n ; j++)
        {
            if(0 == i && 0 ==j )
            {
                if(Count(i) + Count(j) <= k)
                {
                    a[0][0] = 1;
                    total++;
                }

            }
            else
            {
                
                if(Count(i) + Count(j) <= k)
                {
                    tempi = 0<i?i-1:0;
                    tempj = 0<j?j-1:0;

                    if(1==a[tempi][j] || 1==a[i][tempj])
                    {
                        
                        a[i][j] = 1;
                        total++;

                        
                    }
                    else
                    {
                        a[i][j] = 0;
                    }  
                } 
                else
                {
                    a[i][j] = 0;
                }   
            }
   
        }
    }
    
    return total;

}
```