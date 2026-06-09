思路很简单，cost[i]表明是从gas[i]->gas[i+1]的花费，那么我就把在i点加的油和到i+1点的花费和油算成一个整体。

毫无疑问，如果和大于等于0，那么就是能够在油耗尽前到达下一地点得到补充。

那么我们就只需要判断整个从起点出发回到起点的路径上是否我的油能够一直大于等于0，如果能那就是一条合适的路径。

直接附上代码：
```
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
 
    //int index[gasSize];
    int i,sum,j;
    //for(i=0;i<gasSize;i++)
    //index[i]=gas[i]-cost[i];
    for(i=0;i<gasSize;i++)
    {
        //if(index[i]>=0)
        if((gas[i]-cost[i])>=0)
        {
            j=i;
            sum=(gas[j]-cost[j]);
            j++;
            j=j%gasSize;//确保不能越界
            while(j!=i&&sum>=0)
            {
                sum+=gas[j]-cost[j];
                j++;
                j=j%gasSize;
            }
            if(i==j&&sum>=0)
            return i;
        }
    }
    return -1;
}
```
方法二：时间更新为线性O(N)，速度击败100的C语言用户
我们把gas[]和cost[]看成一个数组，那么数组的元素就应该是正负交错，并且，正负元素的个数都是一样的。

我们要求找到一个起点能够环绕一圈。

这里需要理解从该起点开始的元素会形成最大和子数组，换句话来说，你可以理解成我们先走的一段路，从整体上油量是来说是增加的，然后在后一段路油量是递减的。。

这里需要注意一下路是头尾相连的。

这里运用了动态规划。
```
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    long int dp[costSize];//以下标i的元素的最大子序列和
    int index[costSize];
    int i,pos=0,max=0;
    dp[0]=gas[0]-cost[0];//初始化
    index[0]=0;
    for(i=1;i<costSize;i++)
    {
        if(dp[i-1]>=0)
        {
            index[i]=index[i-1];//保存前者的起始下标
            dp[i]=dp[i-1]+(gas[i]-cost[i]);
        }
        else
        {
            dp[i]=gas[i]-cost[i];
            index[i]=i;
        }
        if(dp[i]>max)
            {
                max=dp[i];
                pos=index[i];
            }
    }
    if(dp[costSize-1]>=0)//更新dp[0]，因为前后得相连
    {
        dp[0]+=dp[costSize-1];
        index[0]=index[costSize-1];
        if(dp[0]>max)
            {
                max=dp[0];
                pos=index[costSize-1];
            }
        for(i=1;dp[i-1]>=0&&i<costSize;i++)
            {
                dp[i]+=dp[i-1];
                index[i]=index[i-1];
        if(dp[i]>max)
            {
                max=dp[i];
                pos=index[i-1];
            }
            }
    }
    int pos2=pos;
    int sum=gas[pos]-cost[pos];
    pos++;
    pos%=costSize;
    while(pos!=pos2&&sum>=0)
    {
        sum+=gas[pos]-cost[pos];
        pos++;
        pos%=costSize;
    }
    if(sum>=0)
    return pos2;
    return -1;
}
```
