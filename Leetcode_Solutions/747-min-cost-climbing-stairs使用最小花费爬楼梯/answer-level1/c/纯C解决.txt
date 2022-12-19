
这道题是典型的动态规划的应用。

动态规划的本质就是数学归纳法，所以我们可以这样子理解这道题，我们要求到阶梯顶端的最小花费mark[i]，那么

毫无疑问，我们需要得到mark[i-1],mark[i-2]的最小花费，再加上该阶梯的花费即可。可得式子：

mark[i]=cost[i],i=0,1;

mark[i]=cost[i]+min(mark[i-1],mark[i-2])i>2

```
int min(int a,int b)
{
    if(a<b)
    return a;
    return b;
}
int minCostClimbingStairs(int* cost, int costSize){
    int mark[costSize];
    memset(mark,0,sizeof(int)*costSize);
    mark[0]=cost[0];
    mark[1]=cost[1];
    int i;
    for(i=2;i<costSize;i++)
    {
        mark[i]=min(mark[i-1],mark[i-2])+cost[i];
    }
    if(mark[costSize-1]<mark[costSize-2])
    return mark[costSize-1];
    return mark[costSize-2];
}
```
