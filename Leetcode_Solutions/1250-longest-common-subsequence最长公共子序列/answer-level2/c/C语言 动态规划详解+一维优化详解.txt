### 解题思路
这是一个动态规划的经典问题 首先用dp(i,j)(i为A字符串第i个字符，j为B字符串第j个字符)表示状态
且易知dp(i,j)无后效性(dp(i,j)的最优解与过去无关,无论通过什么方式到达dp(i,j),dp(i,j)的最优解都相同,即无论什么情况下碰到dp(i,j),dp(i,j)的最优解都相同,这也是动态规划记忆化保存重复状态的前提 重复状态的最优解相同) 
然后dp(i,j)有四个行为(若处理成树 则有四个分支) 
1.选i不选j
2.选j不选i
3.选i且选j
4.不选i且不选j
显然第四个分支不可能成为最优解的
要达成第三个分支则需要A[i]==B[j]:if(A[i]==B[j]) dp[i][j]=dp[i-1][j-1]+1
否则在第一 第二个分支中取更大的:else dp[i][j]=max(dp[i-1][j],dp[i][j-1])
注意事项:
字符串数组下标从0开始
故需要提前处理if(i==0||j==0) dp[i][j]
或修改dp(i,j)的状态的含义
i:i为A字符串第i-1个字符
j:j为B字符串第j-1个字符

一维优化:
第一次优化：
两个一维数组代替二维数组：
由递推方程：
if(A[i]==B[j]) dp[i][j]=dp[i-1][j-1]+1
else dp[i][j]=max(dp[i-1][j],dp[i][j-1])
可以看出dp[i][j]的最优解只与dp[i-1][j-1],dp[i-1][j],dp[i][j-1]有关
其中牵涉到的i分量不过只有i和i-1
也即:对于外层循环的一个i所对应的内层循环中的dp[i][j]的最优解只与上一个外层循环i-1所对应的内层循环的dp[i-1][j]有关 和更早之前的i无直接关系
故可以用两个一维数组通过不断迭代进行优化
pre[j]:i-1到j
cur[j]:i到j
于是 递推方程改写为:(暂不考虑越界的问题)
for(i=0;i<Alen;i++)
{for(j=0;j<Blen;j++)
{if(A[i]==B[j]) cur[j]=pre[j-1]+1;//pre[j-1]:dp[i-1][j-1]
else cur[j]=max(pre[j],cur[j-1]);}//pre[j]:dp[i-1][j] cur[j-1]:dp[i][j-1]
int * temp=cur;//为何这里要交换数组指针:pre:i-1到j cur:i到j 当i++后 pre:i到j cur:i+1到j
cur=pre;//故cur数组的值要赋给pre 但为何要交换而不是直接pre=cur呢 
pre=temp;}//因为若不交换而直接pre=cur 则pre和cur同属一个地址 则会产生值的覆盖现象
//例如:cur[j]=pre[j-1]+1;则pre[j]的值也变为了pre[j-1]+1 故要保证cur与pre互不干扰 则每次更新i值之前要交换地址

第二次优化：
一个一维数组代替两个一维数组：
进过分析可以发现 pre数组的设置也属多余
cur[i]表示i到j 当i++时 上一次的cur[j]相对于这一次的cur[j]就是i-1相对于i
也即：cur[j]的旧值相当于i-1到j cur[j]的新值相当于i到j
故可以通过不断迭代更新cur的值 可以省去pre数组
于是 递推方程改写为(暂不考虑越界的问题)
for(i=0;i<Alen;i++)
{pre=0;
for(j=0;j<Blen;j++)
{temp=cur[j];
if(A[i]==B[j]) cur[j]=pre+1;//pre:dp[i-1][j-1] 注释一
else cur[j]=max(cur[j],cur[j-1])// cur[j]:dp[i-1][j] cur[j-1]:dp[i][j-1] 注释二
pre=temp;}}
注释一:为何不是cur[j]=cur[j-1]+1而是cur[j]=pre+1;
因为本来cur[j-1]的旧值表示上一次的i-1到j-1
但cur[j-1]的值在cur[j]之前就被更新了(内循环j在不断增加)
故而此时的cur[j-1]是新值 表示的是i到j-1而非i-1到j-1
而在上个内循环中temp保留了cur[j-1]的旧值 pre又等于temp
由于temp要保留这一次cur[j]的旧值 所以需要pre保留上一次cur[j-1]的旧值
这就是pre和temp的作用
注释二:cur[j]尚未更新 故cur[j]的旧值仍为上一次的i-1到j 而cur[j-1]的值在cur[j]之前便更新
故cur[j-1]的新值为这一次的i到j-1

这样最后返回cur[Blen]的值即可(因为此时的i也已走到Alen) cur[Blen]:dp[Alen][Blen]

最后 再把越界的情况考虑一下 只需改变i和j的状态含义即可 i:A字符串第i-1个字符
j:B字符串第j-1个字符

完整代码如下

### 代码

```c
int max(int a,int b){
if(a>b) return a;
return b;}
int longestCommonSubsequence(char * text1, char * text2){
int i,j;
int temp;
int pre;
int len1;
int len2;
len1=strlen(text1);
len2=strlen(text2);
int cur[len2+1];
memset(cur,0,sizeof(cur));
for(i=1;i<=len1;i++)
{pre=0;
for(j=1;j<=len2;j++)
{temp=cur[j];
if(text1[i-1]==text2[j-1]) cur[j]=pre+1;
else cur[j]=max(cur[j],cur[j-1]);
pre=temp;}}
return cur[len2];
}



/*常规动态规划二维数组解法
int max(int a,int b){
if(a>b) return a;
return b;}
int longestCommonSubsequence(char * text1, char * text2){
int i,j,k;
int len1;
int len2;
len1=strlen(text1);
len2=strlen(text2);
int dp[len1][len2];
if(text1[0]==text2[0]) dp[0][0]=1;
else dp[0][0]=0;
for(i=1;i<len1;i++)
{if(text1[i]==text2[0]) dp[i][0]=1;
else dp[i][0]=dp[i-1][0];}
for(j=1;j<len2;j++)
{if(text1[0]==text2[j]) dp[0][j]=1;
else dp[0][j]=dp[0][j-1];}
for(i=1;i<len1;i++)
for(j=1;j<len2;j++)
{if(text1[i]==text2[j]) dp[i][j]=dp[i-1][j-1]+1;
else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);}
return dp[len1-1][len2-1];
}
*/
```
运行结果：
![捕获.PNG](https://pic.leetcode-cn.com/c4a5447e9accff83c4837b4cec3a6958c56ccb27fac64c02b6f4189d1725d13f-%E6%8D%95%E8%8E%B7.PNG)
时间复杂度 o(n^2)
空间复杂度 o(n)