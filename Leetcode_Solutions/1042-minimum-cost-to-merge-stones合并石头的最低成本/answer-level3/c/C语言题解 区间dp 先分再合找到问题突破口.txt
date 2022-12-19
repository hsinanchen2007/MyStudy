首先设dp[i][j]表示满足能合并成一堆的条件下区间[i,j]内所有石子合并成一堆的最小代价
那么在最后一步合并状态中 区间[i,j]中的(j-i+1)堆石子已经合并成了k堆(k个区间)
此时只要把k堆石子合并即可
此时如何分割区间使得成本最低是问题的关键
此时设有k-1个数将区间[i,j]分成k个区间
则状态转移方程可表示为:
dp[i][j]=min(dp[i][j],dp[i][k1]+dp[k1][k2]+dp[k2][k3]+......+dp[kn-1][j]+s[i][j]);
其中任意一段区间[Kn-1,Kn]均可满足合并成一堆的条件
但通过k-1层枚举找出这k-1个数显然复杂度过高
容易发现 **完全可以将前k-1个区间合并作为一个大区间来考虑 正所谓先分再合 找到问题突破口**
也即：原问题为找出k个区间使得区间[i,j]内所有石子合并成一堆的代价最小
现在问题可转化为：**合并前k-1个区间 即dp[i][kn-1]=dp[i][k1]+dp[k1][k2]+dp[k2][k3]+......+dp[kn-2][kn-1];又因为k-1个区间不可能合并成一堆 故dp[i][kn-1]不会加上s[i][kn-1] 故恰好有dp[i][kn-1]=dp[i][k1]+dp[k1][k2]+dp[k2][k3]+......+dp[kn-2][kn-1];
最终：
dp[i][j]=min(dp[i][j],dp[i][kn-1]+dp[kn-1][j]+s[i][j])**
类似的
对于不满足能合并成一堆的条件下的区间[i,j]
dp[i][j]的含义为在区间[i,j]中的(j-i+1)堆石子合并成相应固定堆数的最小代价
仿照前文 给出状态转移方程
dp[i][j]=min(dp[i][j],dp[i][kn-1]+dp[kn-1][j]) //由于不能合成一堆 故不能加上s[i][j]
故最终状态转移方程为：
for(k=K;k<stonesSize;k++)
for(i=0;i+k<stonesSize;i++)
for(j=i+k-1;j>=i;j-=(K-1))//注释
{if((k+1-K)%(K-1)==0) dp[i][i+k]=min(dp[i][i+k],dp[i][j]+dp[j+1][i+k]+s[i][i+k]);
else dp[i][i+k]=min(dp[i][i+k],dp[i][j]+dp[j+1][i+k]);}
注释：由于每个小区间都可以合并成一堆 故j每次需变化K-1使得每个小区间均满足合并成一堆的条件

初始化：
初始化区间长度为K的所有dp[i][i+K-1]
dp[i][i+K-1]=s[i][i+K-1]//合并K堆成一堆的代价
对于区间长度小于K的做置零处理 因为区间长度小于K的区间无法合并 故其代价为零

完整代码如下：


```
int min(int a,int b){
if(a<b) return a;
return b;}
int mergeStones(int* stones, int stonesSize, int K){
if((stonesSize-K)%(K-1)!=0) return -1;
int i,j,k;
int dp[stonesSize][stonesSize];
memset(dp,0,sizeof(dp));
int s[stonesSize][stonesSize];
for(i=0;i<stonesSize;i++)
{s[i][i]=stones[i];
for(j=i+1;j<stonesSize;j++)
s[i][j]=s[i][j-1]+stones[j];}
for(i=0;i+K-1<stonesSize;i++)
dp[i][i+K-1]=s[i][i+K-1];
for(k=K;k<stonesSize;k++)
{for(i=0;i+k<stonesSize;i++)
for(j=i+k-1;j>=i;j-=(K-1))
{if((k+1-K)%(K-1)==0)
{if(dp[i][i+k]==0) dp[i][i+k]=dp[i][j]+dp[j+1][i+k]+s[i][i+k];
else dp[i][i+k]=min(dp[i][i+k],dp[i][j]+dp[j+1][i+k]+s[i][i+k]);}
else
{if(dp[i][i+k]==0) dp[i][i+k]=dp[i][j]+dp[j+1][i+k];
else dp[i][i+k]=min(dp[i][i+k],dp[i][j]+dp[j+1][i+k]);}
}}
return dp[0][stonesSize-1];
}
```

运行结果
![捕获.PNG](https://pic.leetcode-cn.com/91811883355a4e6e5711999acc544503cfb877c189a2ef0e7b84517788f19f00-%E6%8D%95%E8%8E%B7.PNG)

时间复杂度：o(n^3) 三层循环
空间复杂度：o(n^2) 来源于动态规划二维数组