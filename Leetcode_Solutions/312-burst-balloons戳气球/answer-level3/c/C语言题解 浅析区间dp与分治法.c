区间dp是分治思想的一个应用 
**大区间的解可以由小区间的解合并而成 故先将大区间分解成小区间 最后再将小区间的解合并得到大区间的解**
**体现了分而治之再归并的分治法思想**
故区间dp所要做的就是：
1.如何划分
2.在何处划分
在何处划分只需要枚举区间中的一个分割点即可 最关键的是确立“如何划分”这个问题
既然区间dp用到了分治法的思想 则可以用分治法来思考问题
分治法分解子问题的一个重要特点就是**子问题彼此独立 互不干扰**
所以在“如何划分”这个问题上也应该遵守划分的子区间之间彼此独立 互不干扰
现在有一区间[i,j]在区间中选取一点k 将区间拆分为[i,k-1],[k+1,j]
如果戳爆第k个气球 毫无疑问 两个区间将会产生交集 k-1与k+1将会直接相邻 子问题无法做到彼此独立 互不干扰
但现在换一种思路：
先分别求出区间[i,k-1]与区间[k+1,j]的解 再戳爆第k个气球 这样两个区间就不会产生交集 两个区间的求解过程彼此独立 互不干扰
每求完一段区间的解 该区间的气球数都会变成零
故当求解完两端区间的解时 只剩下了三个气球 i-1 k j+1 故此时再戳爆第k个气球 
得到 nums[i-1]xnums[k]xnums[j+1]
故状态转移方程为dp[i][j]=max(dp[i][j],dp[i][k-1]+dp[k+1][j]+nums[i-1]xnums[k]xnums[j+1]);
注意边界条件 不要让数组越界

完整代码如下:

```
int max(int a,int b){
if(a>b) return a;
return b;}
int maxCoins(int* nums, int numsSize){
if(numsSize==0) return 0;
if(numsSize==1) return nums[0];
int i,j,k;
int dp[numsSize][numsSize];
memset(dp,0,sizeof(dp));
dp[0][0]=nums[0]*nums[1];
for(i=1;i<numsSize-1;i++)
dp[i][i]=nums[i-1]*nums[i]*nums[i+1];
dp[numsSize-1][numsSize-1]=nums[numsSize-2]*nums[numsSize-1];
for(k=1;k<numsSize;k++)
for(i=0;i+k<numsSize;i++)
for(j=i;j<=i+k;j++)
{if(i==0&&i+k==numsSize-1) 
{if(j==0) dp[i][i+k]=max(dp[i][i+k],dp[j+1][i+k]+nums[j]);
else if(j==numsSize-1) dp[i][i+k]=max(dp[i][i+k],dp[i][j-1]+nums[j]);
else dp[i][i+k]=max(dp[i][i+k],dp[i][j-1]+dp[j+1][i+k]+nums[j]);}
else if(i==0) 
{if(j==0) dp[i][i+k]=max(dp[i][i+k],dp[j+1][i+k]+nums[j]*nums[i+k+1]);
else if(j==numsSize-1) dp[i][i+k]=max(dp[i][i+k],dp[i][j-1]+nums[j]*nums[i+k+1]);
else dp[i][i+k]=max(dp[i][i+k],dp[i][j-1]+dp[j+1][i+k]+nums[j]*nums[i+k+1]);}
else if(i+k==numsSize-1) 
{if(j==0) dp[i][i+k]=max(dp[i][i+k],dp[j+1][i+k]+nums[i-1]*nums[j]);
else if(j==numsSize-1) dp[i][i+k]=max(dp[i][i+k],dp[i][j-1]+nums[i-1]*nums[j]);
else dp[i][i+k]=max(dp[i][i+k],dp[i][j-1]+dp[j+1][i+k]+nums[i-1]*nums[j]);}
else 
{if(j==0) dp[i][i+k]=max(dp[i][i+k],dp[j+1][i+k]+nums[i-1]*nums[j]*nums[i+k+1]);
else if(j==numsSize-1) dp[i][i+k]=max(dp[i][i+k],dp[i][j-1]+nums[i-1]*nums[j]*nums[i+k+1]);
else dp[i][i+k]=max(dp[i][i+k],dp[i][j-1]+dp[j+1][i+k]+nums[i-1]*nums[j]*nums[i+k+1]);}}
return dp[0][numsSize-1];
}
```
运行结果:
![捕获.PNG](https://pic.leetcode-cn.com/96e181013909c33492d33a2b61a59836beb9b0e346e190dd12e05eff11036dff-%E6%8D%95%E8%8E%B7.PNG)

时间复杂度:o(n^3) 来源于三层循环
空间复杂度:o(n^2) 来源于二维动态规划数组