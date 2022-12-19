### 解题思路
创建2个一维数组pre和dp，pre[i]表示到上一行的第i个位置的最短距离，dp[i]表示到这一行的第i个位置的最短距离。
递推式为dp[i]=min(pre[i-1],pre[i])+这个位置的triangle值。
每次求完一行后，将pre的值更新，pre[i]=dp[i]。
时间复杂度O(N^2)
空间复杂度O(N)
实际用时0ms，超过100%

### 代码

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int len=triangle.size();
        vector<int>dp(len);
        vector<int>pre(len);
        pre[0]=triangle[0][0];
        for(int i=1;i<len;i++){
            dp[0]=pre[0]+triangle[i][0];
            for(int j=1;j<i;j++){
                dp[j]=min(pre[j-1],pre[j])+triangle[i][j];
            }
            dp[i]=pre[i-1]+triangle[i][i];
            for(int j=0;j<=i;j++){
                pre[j]=dp[j];
            }
        }
        int ans=pre[0];
        for(int i=0;i<len;i++){
            ans=ans<pre[i]?ans:pre[i];
        }
        return ans;
    }
};
```