### 解题思路
![微信图片_20200315111428.png](https://pic.leetcode-cn.com/94af679d66c96a2647fd0ab6dc993fd3cbbbac42808c4e6eb8810612580bb1ed-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200315111428.png)
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int size = prices.size();
        if(size == 0)
            return 0;
        if(k > size / 2)
        {
            int sum = 0;
            for(int i = 0; i < size-1; ++i)
            {
                if(prices[i] < prices[i+1])
                    sum += prices[i+1] - prices[i];
            }
            return sum;
        }
        int max_k = k;
        int dp[size][max_k+1][2];
        for(int i = 0;  i <= k; ++i)
        {
            dp[0][i][1] = -prices[0];
            dp[0][i][0] = 0;
        }
        dp[0][0][1] = 0x80000000;
        for(int i = 1; i < size; ++i)
        {
            dp[i][0][1] = 0x80000000;
            dp[i][0][0] = 0;
        }
        for(int i = 1; i < size; ++i)
            for(int k = max_k; k != 0; --k)
            {
                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
            }
        return dp[size-1][k][0];


        // 我真的感动哭了
        // 下边都是我错误的尝试
        // 一定一定要定义k = 0 和i = 0这两种base case；
        
    //     int size = prices.size();
    //     int j = k;
    //     if(size == 0)
    //         return 0;
    //     int dp[size][k+1][2];
    //     for (int i = 0; i < size; i++) {
    //         for (int k = j; k >= 1; k--) {
    //             if (i - 1 == -1) { 
    //                 /* 处理 base case */
    //                 dp[i][k][0] = 0;
    //                 dp[i][k][1] = -prices[i];
    //                 continue;
    //             }
    //             dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
    //             dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
    // }
}
//    return dp[size-1][j][0];

        // int size = prices.size();
        // if(k == 0 || size == 0)
        //     return 0;
        // int dp[size][k+1][2];
        // // for(int i = 1; i <= k; ++i)
        // // {
        // //     dp[0][i][0] = 0;
        // //     dp[0][i][1] = -prices[0];
        // // }

        // // dp[0][0][1] = -prices[0];
        // // dp[0][0][0] = 0;
        // // dp[0][1][1] = -prices[0];
        // // dp[0][1][0] = 0;
        // // for(int i = 0; i < k; ++i)
        // // {
        // //     dp[0][i][1] = -prices[0];
        // //     dp[0][i][0] = 0;
        // // }
        // // dp[0][0][0] = 0;
        // // dp[0][0][1] = -prices[0];
        // // dp[0][1][0] = 0;
        // // dp[0][1][0] = -prices[0];
        // for(int i = 0; i < size; ++i)
        //     for(int j = k; j >= 1; --j)
        //     {
        //         if(i - 1 == -1)
        //         {
        //             dp[i][j][0] = 0;
        //             dp[i][j][1] = -prices[i];
        //             continue;
        //         }
        //         dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
        //         dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);
        //     }
        
        // return dp[size-1][k][0];
};
```