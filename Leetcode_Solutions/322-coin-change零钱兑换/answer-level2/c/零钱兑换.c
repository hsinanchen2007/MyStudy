### 解题思路
先熟悉背包算法的递归思路再做这道题

### 代码

```c


int coinChange(int* coins, int coinsSize, int amount){
    int max=(int)((unsigned)(~0)>>1);
    //建立一个数组SumOfAmount，
    //SumOfAmount[i]的意思是如果总金额是i的情况下，根据当前几种硬币的面值，最少需要几个硬币可以凑成i
    int *SumOfAmount=(int *)malloc(sizeof(int)*(amount+1));
    SumOfAmount[0]=0;
    //从总金额是1开始一直到总金额是amount，计算每个总金额对应的最少硬币数量
    for(int NumOfAmount=1;NumOfAmount<=amount;++NumOfAmount)
    {
        //还没计算的“最小硬币数”先填充成很大的一个数，方便后边计算辨认。
        SumOfAmount[NumOfAmount]=max;
        //尝试用每种硬币凑总金额，选出用量最少的
        for(int NumOfCoins=0;NumOfCoins<coinsSize;++NumOfCoins)
            //如果这种硬币的面值不比总金额大，且用这种硬币用来凑总金额时，已知最少用量(如果未知，说明还没找到找零的方案)。
            //注意：如果采用一种硬币找零，总金额是会减少相应硬币的面值数的 即NumOfAmount-coins[NumOfAmount]
            if(coins[NumOfCoins]<=NumOfAmount&&SumOfAmount[NumOfAmount-coins[NumOfCoins]]!=max)
                //当总金额是NumOfAmount的时候，最少的硬币用量是：
                //如果不用这种硬币找零的硬币用量数 和 用这种硬币找零之后的硬币用量数 之间较小的那个值
                SumOfAmount[NumOfAmount]=
                SumOfAmount[NumOfAmount]<SumOfAmount[NumOfAmount-coins[NumOfCoins]]+1?
                SumOfAmount[NumOfAmount]:SumOfAmount[NumOfAmount-coins[NumOfCoins]]+1;
    }
    int minSum=SumOfAmount[amount]==max?-1:SumOfAmount[amount];
    free(SumOfAmount);
    return minSum;
}


```