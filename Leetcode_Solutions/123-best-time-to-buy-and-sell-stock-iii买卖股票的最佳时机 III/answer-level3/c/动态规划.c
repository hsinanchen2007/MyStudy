### 解题思路
此处撰写解题思路

### 代码

```c
int maxValue(int a,int b)
{
    if(a >=b)
    {
        return a;
    }
    return b;
}

int maxProfit(int* prices, int pricesSize){

    int k = 2;
    int **sell = (int**)malloc(sizeof(int*)*pricesSize); 
    int **buy = (int**)malloc(sizeof(int*)*pricesSize);
    if (pricesSize == 0)
    {
        return 0;
    }

    for(int i =0;i < pricesSize;i++)
    {
        sell[i] = (int*)malloc(sizeof(int)*(k+1));
        buy[i] = (int*)malloc(sizeof(int)*(k+1));
        memset(sell[i],0x0,sizeof(int)*(k+1));
        memset(buy[i],0x0,sizeof(int)*(k+1));

        for(int j = 1;j <=k;j++)
        {
            buy[i][j] = -0x7fffffff;
        }
    }

    
    for(int i = 0;i < pricesSize;i++)
    {
        for(int j=1;j <=k;j++)
        {
            if (i == 0)
            {
                sell[i][j] = 0;
                buy[i][j] = 0-prices[i];
            }
            else
            {
                sell[i][j] = maxValue(sell[i-1][j],buy[i-1][j]+prices[i]);
                buy[i][j] = maxValue(buy[i-1][j],sell[i-1][j-1]-prices[i]);
            }
        }
    }

    return sell[pricesSize-1][k];
    
}
```