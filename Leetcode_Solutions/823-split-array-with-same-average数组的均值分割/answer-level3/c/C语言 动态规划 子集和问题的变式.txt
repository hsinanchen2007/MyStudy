从原数组中拿走若干个数 使得拿走的数和剩下的数的平均值相等
设原数组的长度为n 总和为sum 拿走的数的个数为k 总和为s
则有:(sum-s)/(n-k)=s/k
(sum-s)*k=s*(n-k)
sum*k=s*n
即确立了一个k和sum就可以判断出这个k和sum是否能满足数组的均值分割
k和sum的关系是任意选取k个数使得这k个数之和为sum
这可以看成**子集和问题的一个变种** 加了k的个数限制
处理方法就是把k加入状态
这样就可以表示为:dp[i][j][k]
状态转移方程为:dp[i][j][k]=judge(dp[i-1][j][k],dp[i-1][j-A[i]][k-1])
再加上判断k和sum是否能满足数组的均值分割 核心代码可写成:
for(i=0;i<ASize;i++)
for(j=A[i];j<sum;j++)//j不能取满 B和C均不能为空
for(k=1;k<=i;k++)//k不能取满 B和C均不能为空
{if(dp[i-1][j-A[i]][k-1]==true) {dp[i][j][k]=true;if(sum*k=s*n) return true;}
else if(dp[i-1][j][k]==true) dp[i][j][k]=true;
else dp[i][j][k]=false;}
但如果用三维数组表示dp 则数组可能过大
此时应采用滚动数组的处理方法
每一次的dp[i]只与dp[i-1]有关
故可以降一维 去掉i这一维达到简化数组的目的
通过不断迭代 新值迭代旧值来降维
由于确立dp[i][j][k]要用到dp[i-1][j][k]和dp[i-1][j-A[i]][k-1]的值
即dp[j][k]=judge(dp[j][k],dp[j-A[i]][k-1])
由于还未更新dp[j][k]的值 故dp[j][k]仍为旧值
欲保证dp[j-A[i]][k-1]也为旧值 即保证dp[j-A[i]][k-1]尚未更新 即保证dp[j-A[i]][k-1]在dp[j][k]之后遍历 故而j和k应从大到小遍历
最终核心代码为:
for(i=0;i<ASize;i++)
for(j=sum-1;j>=A[i];j--)
for(k=i;k>=1;k--)
if(dp[j-A[i]][k-1]==true){dp[j][k]=true;if(s*ASize==sum*k) return true;}
//如果dp[j-A[i][k-1]]==true 则无论dp[j][k]的值是true还是false dp[j][k]都为true
//如果dp[j-A[i]][k-1]==false 则dp[j][k]仍为其旧值 无论真假 
//设计代码时应尽量避免冗余 应设计简洁而全面的代码

时间复杂度:o(sumASizeASize)
sum最大为300000 
ASize最大为30
故最终最大可能做2.7亿次运算 就这道题而言 时间上勉强可以接受 但不是最优解法 只作为dp的一种思想运用
尤其可作为子集和问题的一个变种
空间复杂度o(sumASize)
完整代码如下


```
bool splitArraySameAverage(int* A, int ASize){
int i,j,k;
int sum=0;
for(i=0;i<ASize;i++)
sum+=A[i];
int dp[ASize+1][sum+1];
memset(dp,0,sizeof(dp));
dp[0][0]=1;
for(i=0;i<ASize;i++)
for(k=i;k>=1;k--)
for(j=sum;j>=A[i];j--)
if(dp[k-1][j-A[i]]) {dp[k][j]=1;if(sum*k==j*ASize) return true;}
return false;
}
```
运行结果:

![捕获.PNG](https://pic.leetcode-cn.com/5016bb821938cbd43c067eec7cd88b9a66359a5dd656d832a66f8c7b4d454e5c-%E6%8D%95%E8%8E%B7.PNG)

