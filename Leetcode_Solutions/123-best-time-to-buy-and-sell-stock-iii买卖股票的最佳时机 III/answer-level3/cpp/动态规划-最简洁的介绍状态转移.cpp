### 解题思路
此处撰写解题思路
状态转移
result = d（postion, 剩余交易次数, 手中是否持有股票）
    d(i, k, 0) = max(d(i-1, k, 0), d(i-1, k, 1)+prices[i])
    d(i, k, 1) = max(d(i-1, k, 1), d(i-1, k+1, 0) - prices[i])
最终结果从d(len-1, 2, 0) d(len-1, 1, 0) d(len, 0, 0)中选取
4 ms, 在所有 cpp 提交中击败了98.76%
的用户

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0) {
            return 0;
        }
        int d[len+1][3][2]={0};
        d[0][0][0] = INT_MIN+100000;
        d[0][0][1] = INT_MIN+100000;
        d[0][1][1] = -prices[0];
        d[0][1][0] = INT_MIN+100000;
        d[0][2][0] = 0;
        d[0][2][1] = INT_MIN+100000; 
        for (int i = 1; i < len; i++) {
            for (int k = 1; k >= 0; k--) {
                d[i][k][0] = max(d[i - 1][k][0], d[i - 1][k][1] + prices[i]);
                d[i][k][1] = max(d[i - 1][k][1], d[i - 1][k + 1][0] - prices[i]);
            }
        }
        return max(0, max(d[len-1][1][0], d[len-1][0][0]));
    }
};
```