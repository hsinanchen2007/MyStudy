    这就有一个尴尬的地方，动态规划应该只用一个dp，在取舍是左到右还是上到下的时候，你第一反应是哪个dp小取哪个，但是有可能hp也会对判断造成干扰[[1,-3,3],[0,-2,0],[-3,-3,-3]]也就是在计算dp[1][2][0]的时候应当是选择从dp[0][2][0]那条路线而非选择dp[1][2][0]那条路线。出现了错误同上。因此，应当从右下角开始回到起点。
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // int m=dungeon.size();
        // int n=dungeon[m-1].size();
        // vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(2,0)));
        // if(dungeon[0][0]>=0)
        // {
        //     dp[0][0][0]=0;
        //     dp[0][0][1]=dungeon[0][0];
        // }
        // else
        // dp[0][0][0]=dp[0][0][1]=dungeon[0][0];
        // for(int i=1;i<n;++i)
        // {
        //     dp[0][i][1]=dp[0][i-1][1]+dungeon[0][i];
        //     dp[0][i][0]=min(dp[0][i][1],dp[0][i-1][0]);
        // }
        // for(int i=1;i<m;++i)
        // {
        //     dp[i][0][1]=dp[i-1][0][1]+dungeon[i][0];
        //     dp[i][0][0]=min(dp[i-1][0][0],dp[i][0][1]);
        // }
        // int now1,now2,now3,now4;
        // for(int i=1;i<m;++i)
        // {
        //     for(int j=1;j<n;++j)
        //     {
        //         now1=dp[i-1][j][1]+dungeon[i][j];
        //         now2=dp[i][j-1][1]+dungeon[i][j];
        //         now3=min(now1,dp[i-1][j][0]);
        //         now4=min(now2,dp[i][j-1][0]);
        //         // now3=min(now1,now3);
        //         // now4=min(now2,now4);
        //         if(now3>now4)
        //         {
        //             dp[i][j][0]=now3;
        //             dp[i][j][1]=now1;
        //         }
        //         else
        //         {
        //             dp[i][j][0]=now4;
        //             dp[i][j][1]=now2;                    
        //         }
        //     }
        // }
        // if(dp[m-1][n-1][0]>0)
        // return 1;
        // else
        // return 1-dp[m-1][n-1][0];
    }
};