**题解1：滑动窗口**

题目重点语句：**如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是湍流子数组**。通俗点解释就是`<、>、<、>`要交替出现，不能出现连续的`>、>`或`<、<`或`>、=`或`<、=`。对于本题例子`9 4 2 10 7 8 8 1 9`，我们用-1，0，1来b表示两个数字之间的符号（小于，等于，大于），也就是说n个数字将产生n-1个符号，将例子转换后的结果为9 `1>`4 `1>` 2 `-1<` 10 `1>` 7 `-1<` 8 `0=` 8 `1>` 1 `-1<` 9 。窗口内的符号为`1,1,-1,1,-1,0,1,-1`，然后当我们遇到连续两个符号相等或符号为0时，也就是当我们发现湍流不成立时，我们需要划分窗口，所以可划分为四个窗口,`1`,`1,-1,1,-1`,`0`,`1,-1`。

**代码如下：**
```cpp
class Solution {
public:
    int compare(int a,int b){
        return (a>b)?1:(a==b)?0:-1;
    }
    
    //题解1：滑动窗口
    int maxTurbulenceSize(vector<int>& A) {
        if(A.empty())return 0;
        
        //初始化窗口边界，result以及数组边界
        int left=0,right=1,result=1,N=A.size();
        
        while(right<N)
        {
            int flag=compare(A[right-1],A[right]);
            
            //到达数组末尾或者湍流不成立时，开始划分窗口
            if(right==N-1||flag*compare(A[right],A[right+1])!=-1)
            {
                if(flag!=0)result=max(result,right-left+1);//划分窗口，更新result值
                left=right;//窗口左边界右移
            }
            ++right;
        }
        return result;
    }
   }
};
```

**题解2：动态规划**
状态dp[i]表示以A[i]结尾的最长湍流子数组的长度，注意以A[i]结尾是必须的。
这样我们来分析状态转移方程了:
* 1）若`A[i-2],A[i-1],A[i]`构成一个湍流数组成立，那么dp[i]=dp[i-1]+1。通俗点解释就是上一个湍流子数组加上A[i]后生成的新的湍流数组，新的湍流数组长度也就是上一个最长湍流子数组的长度dp[i-1]+1。
* 2）若湍流数组不成立，那么我们需要比较A[i-1]与A[i]是否相等来确定dp[i]的值。若`A[i-1]!=A[i]`,则dp[i]=2;若`A[i-1]==A[i]`,则dp[i]=1。

**代码如下：**
```cpp
class Solution {
public:
    int compare(int a,int b){
        return (a>b)?1:(a==b)?0:-1;
    }
     //题解2：动态规划
    int maxTurbulenceSize(vector<int>& A) {
        if(A.size()<2)return A.size();
        
        int N=A.size(),dp[N];
        memset(dp,1,sizeof(dp));
        
        dp[0]=1;
        dp[1]=(A[1]!=A[0])?2:1;
        
        int result=max(dp[0],dp[1]);
        
        for(int i=2;i<N;++i)
        {
           if(compare(A[i-2],A[i-1])*compare(A[i-1],A[i])==-1){//瑞流成立
               dp[i]=dp[i-1]+1;
               result=max(result,dp[i]);//更新result
           }else if(compare(A[i-1],A[i])!=0){//瑞流不成立且两数不相等，dp[i]=2
               dp[i]=2;
           }
        }
        return result;
    }
};
```
补充：对于这种连续子数组或者子序列的题，我们用动态规划思想的话，可以将状态方程设计为以下两种形式：
* 1）令dp[i]表示以A[i]开头（或结尾）的***
* 2）令dp[i][j]表示A[i]至A[j]区间的***
* 注：这里的***表示对原问题的描述。

本人博客：[这里](https://blog.csdn.net/qq_43152052/article/details/102632653)。
