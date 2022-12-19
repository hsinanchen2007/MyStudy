```c++
class Solution {
public:
    
    // 对于两个字符串的问题 似乎都是动态规划 <1>常规的动态规划:消耗空间较大,但根据转移方程基本不会有问题
    // <2>节约空间的动态规划,比如两个一维数组, 
    //      最容易出问题的地方就是如何保证好边界条件,如果保证不好边界条件,结果就会有问题
    // <3>实际上还有更节省空间的情况, 一个一维数组,我们颠倒i和j变成dp[j][i] 外层for循环针对s 内层针对t;
    //      所以在第j个外循环的时候 对于dp[i]来说  它的值本来就是原来的dp[i][j-1] 
            // 只需要加上dp[i-1][j-1]的值即可,这个值就是dp[i-1],为了不覆盖这个值,
            // 所以内循环到从大到小 从t.size()到1 防止覆盖之前的值
            // 对于边界条件,也要特别注意

    // 动态转移方程 dp[i][j]代表 T的前i个字符  可被S的前j个字符 多少种表示
    // 如果T[i]==S[j],那么有两种选择,让S[j]对应于T[i],接下来就看dp[i-1][j-1]的情况;
    //                            或者不让S[j]对应于T[i], 那么就是dp[i][j-1]的情况。
    // 如果如果T[i]!=S[j],那么对应于不让S[j]对应于T[i], 那么就是dp[i][j-1]的情况。
    // 边界条件则是i==0时的,dp[0][j] === 1 恒为1
    //           j==0时且i!=0,则dp[i][0]=0
    // 所以 i!=0,j!=0, dp= dp[i][j-1] + (T[i]==S[j])?dp[i-1][j-1]:0  ;

      //具体实现上 <1>常规的动态规划
    int numDistinct(string s, string t) {
        int lens=s.size(),lent=t.size();
        s=' '+s; t=' '+t; //加一个空格 使得现在的s[1]对应于之前的s[0] 使用下标的时候不用再特意-1
        vector<vector<long>> dp(lent+1,vector<long>(lens+1)); //开空间 注意使用long 因为个数较多

        for(int i=1; i<=lent;++i) //i！=0 且 j=00的边界情况
            dp[i][0]=0; 

        for(int j=0; j<=lens;++j) // i==0 的边界情况
            dp[0][j]=1; 

        for(int i=1;i<=lent;++i){
            for(int j=1;j<=lens;++j){
                dp[i][j]=dp[i][j-1]; // 不让S[j]对应于T[i],只能是dp[i][j-1]
                if(t[i]==s[j]) 
                    dp[i][j]+=dp[i-1][j-1]; //二者相等 可以让S[j]对应于T[i],所以加上dp[i-1][j-1]
            }
        }
        
        return dp[lent][lens];
    }

    // <2>节省空间的动态规划 相当于两个一维数组
    int numDistinct(string s, string t) {
        int lens=s.size(),lent=t.size();
        s=' '+s; t=' '+t;
        vector<vector<long>> dp(2,vector<long>(lens+1));
       
        for(int j=0; j<=lens;++j) //设置i==0的边界条件
            dp[0][j]=1;
        // 由于我们这里值设置了 i==0 的边界条件 所以在下面对于i!=0, j==0的情况 一定要特别注意
        for(int i=1;i<=lent;++i){
            for(int j=1;j<=lens;++j){
                dp[i%2][j]=dp[i%2][j-1]; //由于只有两个数组 所以对于i和i-1都要有模2的操作
                if(t[i]==s[j])
                    dp[i%2][j]+=dp[(i-1)%2][j-1];
            }
            dp[0][0]=0; //这两步就是为了保证i!=0, j==0的边界情况 始终保持相应的值为0
            dp[1][0]=0;
        }
        
        return dp[lent%2][lens];
    }

    // <3> 一维数组的动态规划
    int numDistinct(string s, string t) {
        int lens=s.size(),lent=t.size();
        s=' '+s; t=' '+t;
        vector<long> dp(lent+1,0);
        dp[0]=1;

        for(int j=1;j<=lens;++j){ //外循环对s的长度 而不是t的长度
            for(int i=lent;i>=1;--i){ //内循环虽然是t的长度 但是是倒着的 
            // 因为需要在计算dp[i][j](dp[i]的值的时候 需要dp[i-1][j-1]的值 
            // 所以要倒着 确保用的时候 这个值还没被覆盖掉从而变成dp[i-1][j]
               if(t[i]==s[j]) //如果相等 dp[i][j]=dp[i-1][j]+ dp[i-1][j-1]
                    dp[i]+=dp[i-1];
            }
            dp[0]=1; //边界条件 当j==0 i!=0时 dp[i][0]=0
        }
        
        return dp[lent]; 
    }

};
```