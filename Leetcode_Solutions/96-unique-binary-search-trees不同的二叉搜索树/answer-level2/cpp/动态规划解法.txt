### 解题思路

![WechatIMG348.png](https://pic.leetcode-cn.com/83d3b58f6161a9bf2fd7b4461fd4502fac493de957758df1c395a7cd5d0c2e7b-WechatIMG348.png)


### 代码

```cpp
class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1,0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                dp[i] += dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};
```