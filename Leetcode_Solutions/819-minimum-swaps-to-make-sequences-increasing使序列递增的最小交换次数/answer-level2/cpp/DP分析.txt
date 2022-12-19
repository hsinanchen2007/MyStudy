```
//dp[i][j]记录0-i保持严格递增的最小交换次数，j表示结束时的状态，存在两个状态(上下交换/不变)
class Solution {
public:
    int len;
    bool judge1,judge2;
    int minSwap(vector<int>& A, vector<int>& B) {
        len = A.size();
        vector<vector<long>> dp(len,vector<long>(2,INT_MAX));
        dp[0][0] = 0;dp[0][1] = A[0]==B[0]?0:1;//初始化
        for(int i=1;i<len;i++) {  
            judge1 = A[i]>A[i-1]&&B[i]>B[i-1];
            judge2 = B[i]>A[i-1]&&A[i]>B[i-1];
            if(A[i]==A[i-1]||B[i]==B[i-1]) {//不交换时无解的情况
                dp[i][0] = dp[i-1][1];
                dp[i][1] = dp[i-1][0] + 1;
            }else if(A[i]==B[i-1]||B[i]==A[i-1]) {//上下交换无解的情况
                dp[i][1] = dp[i-1][1] + 1;
                dp[i][0] = dp[i-1][0];
            }else if(judge1&&!judge2){//不交换时满足严格递增条件，交换时不满足
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1] + 1;
            }else if(judge2&&!judge1) {//交换时满足严格递增条件，不交换时不满足
                dp[i][0] = dp[i-1][1];
                dp[i][1] = dp[i-1][0] + 1;
            }else if(judge1&&judge2){//交换/不交换同时满足严格递增条件
                dp[i][0] = min(dp[i-1][0],dp[i-1][1]);
                dp[i][1] = min(dp[i-1][0],dp[i-1][1]) + 1;
            }
        }
        return min(dp[len-1][0],dp[len-1][1]);
    }
};
```
