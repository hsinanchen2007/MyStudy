### 解题思路
先说一下基本思路。

举个例子，假设我们有[1,2,5],我们需要支付的为N元

那么就一定N-1、N-2、N-5其中一种我们能够凑得齐，并且取凑得其中金额所需的最少张数。

这里给出动态规划的推导，dp[i]=min(dp[i-1]、dp[i-2]、dp[i-5])+1
当然其中i-1,i-2,i-5都是有效下标即可

### 代码
```
//递归，时间超出
int coinChange(int* coins, int coinsSize, int amount){
    int i;
    for(i=0;i<coinsSize;i++)
    if(amount==coins[i])
    {return 1;
   }
    if(amount<coins[0])//小于最小的
    {
        return -1;
    }int coinChange(int* coins, int coinsSize, int amount){
    int i;
    for(i=0;i<coinsSize;i++)
    if(amount==coins[i])
    {return 1;
   }
    if(amount<coins[0])//小于最小的
    {
        return -1;
    }
    else
    {
        int count=amount+1;
        int number;
        for(i=coinsSize-1;i>=0;i--)
        {
            number=coinChange(coins,coinsSize,(amount-coins[i]));
            if(number!=-1)
            count=(count<number?count:number);
        }
        if(count==amount+1)//没有一种方法能股通过
        return -1;
        return count+1;
    }
    return -1;
}

    else
    {
        int count=amount+1;
        int number;
        for(i=coinsSize-1;i>=0;i--)
        {
            number=coinChange(coins,coinsSize,(amount-coins[i]));
            if(number!=-1)
            count=(count<number?count:number);
        }
        if(count==amount+1)//没有一种方法能股通过
        return -1;
        return count+1;
    }
    return -1;
}

```


```c
//动态规划

int coinChange(int* coins, int coinsSize, int amount){
    int i;
    int *dp=(int *)malloc(sizeof(int)*(amount+1));//dp[i]代表i金额最小的
    memset(dp,-1,sizeof(int)*(amount+1));//初始化

    //边界条件
    for(i=0;i<coinsSize&&coins[i]<=amount;i++)
    dp[coins[i]]=1;
    dp[0]=0;
    int j;
    for(i=0;i<=amount;i++)//状态转移方程
    {
        int number=amount+1;
        for(j=0;j<coinsSize;j++)
        {
            if(i-coins[j]>=0&&dp[i-coins[j]]!=-1)//首先下标必须要满足有效区间，第二，上一个金额能够到达
            number=(dp[i-coins[j]]<number?dp[i-coins[j]]:number);
        }
        if(number!=amount+1)
        dp[i]=number+1;
    }
    return dp[amount];
}


```