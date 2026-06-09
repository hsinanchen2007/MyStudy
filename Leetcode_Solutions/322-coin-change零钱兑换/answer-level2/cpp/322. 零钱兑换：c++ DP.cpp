### 解题思路
1.DP的思路不在详细描述，就是取min(dp[i - coin] + 1);，对于用例来说就是取min(dp[i-1]+1,dp[i-2]+1,dp[i-5]+1)
2.有几个坑要注意：
1）因为是取最小值，因此最小值的初值需要赋值，由于纸币最小刻度为1，因此dp最大值为amount，因此最小值可以赋值为amount+1，即minvalue = amount+1
2）dp[0] = 0;由dp[0]推导出后续的dp[coin[i]]

### 代码

```cpp
/*
 * Copyright (c) Huawei Technologies Co., Ltd.2012-2019. All rights reserved.
 * Description:Solution
 * Author: 高阳 g00280552
 * Create: 2019-12-27
 */
#include <vector>
#include <algorithm>
#include <functional>


using namespace std;


class Solution {
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // 初始化最大值为amount+1
        vector<int> dp(amount + 1, amount + 1);
        // Dp[0] = 0 至关重要，因为 1,2,5 对应于dp[i-coin]最终是dp[0],因此代码可以非常简化
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins)
                if (coin <= i)
                    // 实际是取得dp[i - coin]的最小值
                    dp[i] = min(dp[i], dp[i - coin] + 1);
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
```