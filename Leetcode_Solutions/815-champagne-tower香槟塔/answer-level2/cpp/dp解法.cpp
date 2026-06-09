```c++
class Solution {
public:
    /*
    思路：记录每个酒杯的流经的酒的流量dp[i][j],则流到每个酒杯的下面的两个酒杯的酒量
    就等于(dp[i][j]-1)/2,叠加每一层的酒杯上一层的流出来的酒即可,所以有dp的做法.
    */
    double champagneTower(int poured, int q_r, int q_g) {
        vector<vector<double>>dp(q_r+2,vector<double>(q_r+2));
        dp[0][0]=(double)poured;
        for(int i=0;i<=q_r;i++){
            for(int j=0;j<=i;j++){
                double t = (dp[i][j]-1)/2;
                dp[i+1][j]+=t>0?t:0;
                dp[i+1][j+1]+=t>0?t:0;
            }
        }
        return dp[q_r][q_g]>1?1:dp[q_r][q_g];
    }
}; 
```