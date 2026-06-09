### 解题思路
动态规划数组 首先从二维开始
dp[i][j] 代表前i种已经出现的石头，背包容量为j的情况下，能得到的最大值。
寻找dp[i][j]的来源：
1. 如果新出现的第i块石头容量stones[i]已经超过容量j，stones[i]>j，放不进去，此情况下为 dp[i-1][j];
2. stones[i]没有超过容量j，stones[i]<=j，此情况下可以考虑放不放入:
    1. 放入stones[i],那么需要同背包中腾出来stones[i]的空间，此情况下为dp[i-1][j-stones[i]],为何是i-1? 是因为石头是不放回的。要知道dp[i][j-stones[i]],含义是指容量为j-stones[i],然后考虑前i块石头的取舍情况下得到的最大重量，此时就可能已经放入了第i块石头，如果我们再使用dp[i][j-stones[i]]来更新dp[i][j]的值，就可能连续放了两次stones[i]，因此要采用dp[i-1][j-stones[i]];
    2. 不放入stone[i],含义就是容量为j的背包里不放入stones[i]着块石头，相当于不考虑stones[i],那很自然的该情况为dp[i-1][j];
此时总结dp[i][j]的更新来源:
if(stones[i]<=j) dp[i][j] = max(dp[i-1][j-stones[i]],dp[i-1][j]);
else dp[i][j] = dp[i-1][j];

dp[i][j] 这个二维数组，行数就是stones的数量+1,代表依次放入第0,1,2...,stones.size()块石头
最大列数是sum/2+1 这样 右下角为dp[stones.size()][sum/2] 代表了不超过sum/2的最大组合。
初始化要把第0行和第0列的值都置为0。
该部分完整更新代码为
```
for(int i=1;i<stones.size();i++){
    for(int j=stones[i];j<=sum/2;j++) 
        dp[i][j] = j>=stones[i-1]?max(dp[i-1][j],dp[i-1][j-stones[i-1]]+stones[i-1]):dp[i-1][j]; 
}

```
优化部分 ：很容易联想到，上述更新过程只和上一行有关，我们可以把空间复杂度降到两行。
我们还可以进一步优化，降到一行。
我们可以在上一行计算返回的一维数组基础上，直接更新本行结果。需要注意的地方是，如果我们从左向右更新，在更新dp[j]时，所用到的dp[j-stones[i]]实际上是dp[i][j-stones[i]]，（因为从左到右的过程中，dp[j-stones[i]]先于dp[j]更新，更新后就相当于变成了dp[i][j-stones[i]])。解决的方法是从右向左更新，这样dp[j]更新的时候，使用到的dp[j-stones[i]]是没更新的，相当于dp[i-1][j-stones[i]]。

好像有点过于啰嗦了，01背包问题网上有很多资料，此处写的比较详细其实是因为自己在读背包九讲的时候，有一些地方没弄通，此处为了加深理解。

### 代码

```cpp
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        //
        int len = stones.size();
        int sum = 0;
        for(int i=0;i<len;i++) sum += stones[i];
        int templen = sum/2+1;
        int dp[templen]={0};//要尽可能逼近中间值
        for(int i=0;i<len;i++){
            for(int j=templen-1;j>=stones[i];j--){
                dp[j] = max(dp[j],dp[j-stones[i]]+stones[i]);
            }
        }
        return sum - 2*dp[templen-1];
    }
};
```