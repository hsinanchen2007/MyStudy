**简单dp即可,需要注意几点**
1. 状态:dp[k][i]还剩k步时索引i的方案数
2. 转移：dp[k][i]=dp[k+1][i]+dp[k+1][i-1]+dp[k+1][i+1]（在0，n-1索引处特判一下）
3. 动态规划找出这两点就完成一半了，剩下只需考虑边界
4. 注意只会用到小于steps的索引点
 ```
#define ll long long
const long N=1000000007;
class Solution {
public:
    //典型的二维dp:
    // dp[k][i]表示还剩k步时在i索引处的方案数
    //  转移：dp[k][i]=dp[k+1][i]+dp[k+1][i-1]+dp[k+1][i+1]（在0，n-1索引处特判一下）
    //节省空间只需一个滚动数组即可。。没算空间超了一次内存。。
    //注意steps<i,不然超时
    int numWays(int steps, int arrLen) {
       int n=arrLen;
        if(steps==1)return 1;
        vector<vector<ll>>ans(2,vector<ll>(steps,0));
        ans[0][0]=1,ans[0][1]=1;
        //
        for(int k=steps-2;k>=0;k--){
            for(int i=0;i<=k&&i<n;i++){
                if(!i){
                  ans[1][i]=(ans[0][i])%N+(ans[0][1])%N;
                    continue;
            }
                if(i==n-1){
                    ans[1][i]=(ans[0][i])%N+(ans[0][i-1])%N;
                    ans[0][i]=ans[1][i];
                    continue;
                }
                ans[1][i]=(ans[0][i-1])%N+(ans[0][i])%N+(ans[0][i+1])%N;
            }
            for(int i=0;i<=k;i++)ans[0][i]=ans[1][i];
        }
        return ans[0][0]%N;
    }
};
```
另外一种方法是记忆化搜索：从数组除0索引外的每个点到0搜索的方案数之和。