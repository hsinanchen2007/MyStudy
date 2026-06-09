这个题目不能直接用动态规划去解，比如用dp[i]表示前i个人需要的最少糖果数。
因为（前i个人的最少糖果数）这种状态表示会收到第i+1个人的影响，如果a[i]>a[i+1]，那么第i个人应该比第i+1个人多。
即是这种状态表示不具备无后效性。

如果是我们分配糖果，我们应该怎么分配？
答案是：从分数最低的开始。
按照分数排序，从最低开始分，每次判断是否比左右的分数高。
假设每个人分c[i]个糖果，那么对于第i个人有c[i]=max(c[i-1],c[c+1])+1; （c[i]默认为0，如果在计算i的时候,c[i-1]为0，表示i-1的分数比i高）
但是，这样解决的时间复杂度为O(NLogN)，主要瓶颈是在排序。
如果提交，会得到Time Limit Exceeded的提示。

我们需要对贪心的策略进行优化：
我们把左右两种情况分开看。
如果只考虑比左边的人分数高时，容易得到策略：
从左到右遍历，如果a[i]>a[i-1]，则有c[i]=c[i-1]+1；否则c[i]=1。

再考虑比右边的人分数高时，此时我们要从数组的最右边，向左开始遍历：
如果a[i]>a[i+1], 则有c[i]=c[i+1]+1；否则c[i]不变；

这样讲过两次遍历，我们可以得到一个分配方案，并且时间复杂度是O(N)。
```
int candy(int* ratings, int ratingsSize){
    int candy_num[ratingsSize], res = 0;
    candy_num[0] = 1;
    for(int i = 1; i < ratingsSize; i++)
        if(ratings[i] > ratings[i - 1])
            candy_num[i] = candy_num[i-1] + 1;
        else
            candy_num[i] = 1;

    for(int j = ratingsSize - 2; j >= 0; j--)
        if(ratings[j] > ratings[j + 1])
            if(candy_num[j] <= candy_num[j+1])
                candy_num[j] = candy_num[j+1] + 1;

    for(int i = 0; i < ratingsSize; i++)
        res += candy_num[i];
    return res;
}
```
