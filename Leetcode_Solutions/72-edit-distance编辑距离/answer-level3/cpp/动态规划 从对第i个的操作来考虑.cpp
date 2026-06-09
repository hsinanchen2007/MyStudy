

#### 分析

- 状态表示 `dp[i][j]`
    - 集合 ： 所有吧`a`中的`前i个字母` 变成 `b`中`前j个字母的集合`的操作集合
    - 属性 ： 所有操作中`操作次数最少`的方案的`操作数`
- 状态计算
** 状态划分** 以对`a中的第i个字母`**操作**不同划分
    - 在该字母之后添加
        - 添加一个字母之后变得相同，说明没有添加前`a的前i个`已经和`b的前j-1个`已经相同
        - 即 ： `dp[i][j] = dp[i][j-1] + 1`
    - 删除该字母
        - 删除该字母之后变得相同，说明没有删除前`a中前i-1`已经和`b的前j个`已经相同
        - 即 ： `dp[i][j] = dp[i-1][j] + 1`
    - 替换该字母
        - 替换说明对应结尾字母不同，则看倒数第二个
        - 即： `dp[i][j] = dp[i-1][j-1] + 1`
    - 啥也不做
        - 换说明对应结尾字母相同，直接比较倒数第二个
        - 即： `dp[i][j] = dp[i-1][j-1] `
    

#### C++ 代码
```C++
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp (m + 1, vector<int>(n + 1));
        
        for(int i = 0; i <= m; i++) dp[i][0] = i;
        for(int i = 0; i <= n; i++) dp[0][i] = i;
        
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + 1;   //  插入 和 删除 
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (word1[i-1] != word2[j-1])); // 替换 和 什么也不做
            
            }
        }
        
        return dp[m][n];
    }
};
```

----------