### 解题思路
由底向上推不难，思路为dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + dp[i][j]，这里dp[i][j]表示走下往上走的总和

降维的思路：因为存储过多信息纯属浪费，我们这里不需要额外存这么多行的信息
    1. 先存最后一行的信息
    2. 将倒数第二行的更新到最后一行
    3. 依次更新直至最后，第一个数也就是塔顶

所以最终公式为                 dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];

### 代码

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.size() + 1,0);
        for(int i = triangle.size() - 1; i >= 0; i--)
            for(int j = 0; j < triangle[i].size(); j++) 
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];

        return dp[0];
    }
};

```