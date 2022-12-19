执行用时 :
32 ms
, 在所有 C 提交中击败了
100.00%
的用户
内存消耗 :
6.8 MB
, 在所有 C 提交中击败了
100.00%
的用户

首先按照先取大的取的数量少的规律，我们把硬币种类按照从大到小排序；
然后进行递归回溯；
我的回溯函数的参数包括整型m用来记录取硬币的个数，整型p记录当前从第几个开始取，剩下三个参数就是题目提供的数据；
另外我定义一个全局整形变量n，用来记录最少的硬币个数，在开始时先把n初始化为-1；
然后具体回溯的方法如下：
```
for(int i=p;i<coinsSize;i++)
        if(amount-coins[i]>=0)
            ss(m+1,amount-coins[i],i,coins,coinsSize);
```

然后设计剪枝；
当n>0时并且(当前的硬币数量m)+(剩余的amount都取当前种类硬币个数amount/coins[p])>n的情况，直接return，因为此后的硬币价值会越来越小，需要的数量会越来越多，得到的结果一定比当前的n大；
具体写法如下：
```
if(n>0&&m+amount/coins[p]>n)
        return;
```

整体代码：
```
int n;
int cmp(const void* a,const void* b){
    return *(int*)a<*(int*)b;
}
void ss(int m,int amount,int p,int* coins,int coinsSize){
    if(n>0&&m+amount/coins[p]>n)
        return;
    if(amount==0){
        n=m;
        return;
    }
    for(int i=p;i<coinsSize;i++)
        if(amount-coins[i]>=0)
            ss(m+1,amount-coins[i],i,coins,coinsSize);
}
int coinChange(int* coins, int coinsSize, int amount){
    n=-1;
    qsort(coins,coinsSize,sizeof(int),cmp);
    ss(0,amount,0,coins,coinsSize);
    return n;
}
```
