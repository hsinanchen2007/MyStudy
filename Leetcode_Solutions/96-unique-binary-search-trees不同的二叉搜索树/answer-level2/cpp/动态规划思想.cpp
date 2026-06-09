### 解题思路
动态规划
dp[i]——————i个节点能有多少个二叉搜索子树——————左边的子树的个数*右边的子树的个数
以j为分叉点，左边1~j,右边j+1~i,
即左边j-1,右边i-(j+1)+1=i-j个

### 代码

```cpp
class Solution {
public:
    
    int numTrees(int n) {
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];

    }
};
```