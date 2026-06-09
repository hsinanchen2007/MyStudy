```
class Solution {//因为最小代价树的子树也是最小代价树，故可以dp思想
public://执行用时 :4 ms, 在所有 C++ 提交中击败了95.18%的用户
    int i,j,k,len,mini;
    int dp[40][40];//代表从位置i到j合并的代价树的最大叶子结点值
    int sum[40][40];//代表从位置i到j合并的代价树的最小代价
    int mctFromLeafValues(vector<int>& arr) {
        len = arr.size();
        for(i=0;i<len;i++) dp[i][i] = arr[i];
        for(k=2;k<=len;k++) {
            for(i=0;i<=len-k;i++) {
                sum[i][i+k-1] = INT_MAX;
                for(j=i;j<i+k-1;j++) {
                    mini = sum[i][j] + sum[j+1][i+k-1] + dp[i][j]*dp[j+1][i+k-1];;
                    if(mini<sum[i][i+k-1]) {
                        sum[i][i+k-1] = mini;//更新最小代价
                        dp[i][i+k-1] = max(dp[i][j],dp[j+1][i+k-1]);//更新最小结点值
                    }
                }
            }
        }
        return sum[0][len-1];
    }
};
```
