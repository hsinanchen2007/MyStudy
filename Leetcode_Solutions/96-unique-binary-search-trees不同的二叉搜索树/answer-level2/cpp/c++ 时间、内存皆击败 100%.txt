### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numTrees(int n) {
        if(n <= 2)
            return n;
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for(int i = 1; i <= n; i++){
            int temp = 0;
            for(int j = 1; j <= i; j++){
                temp += dp[j - 1] * dp[i - j];
            }
            dp[i] = temp;
        }
        return dp[n];

    }
};
```