```
const int maxn=1e4+10;
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        //动态规划
        //基本思路：dp[i]代表的是在i点之前所需要的最少水龙头个数
        //第i个水龙头所覆盖的面积是max(i-ranges[i],0)~min(n,i+ranges[i]),
        //所以更新这一区域的dp就可以啦，dp本质就是之后的情况受之前情况影响的。。。
        int dp[maxn];
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        for(int i=0;i<=n;i++){
            int left=max(0,i-ranges[i]);
            int right=min(n,i+ranges[i]);
            //cout<<left<<right<<endl;
            for(int j=left;j<right;j++){//枚举left~right之间的情况(第i个水龙头的情况)
                if(dp[j]==-1)continue;//表示这一点目前不存在符合条件的解
                if(dp[right]==-1||dp[right]>dp[j]+1){
                    dp[right]=dp[j]+1;
                }
                //dp[right]=min(dp[right],dp[j]+1);

            }
            //cout<<dp[right]<<endl;
        }
        return dp[n];

    }
};
```
