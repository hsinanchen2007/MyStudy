
根据题意，两次交易不能有重合。原题可以转化为：以 i 为切割点，左右两部分分别进行一笔交易赚的最大利润，即为这种情况下的最大利润。遍历所有可能 i 即可知道最终答案。

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int result = 0;
        // right[i] 代表从 i 开始的 prices 序列，能赚的最大的钱
        vector<int> right = vector(n,0);
        int maxRight = 0;
        int resRight = 0;
        for(int i=n-1;i>=0;i--) {
            // 倒序遍历，动态规划得到 right 数组
            maxRight = max(prices[i], maxRight);
            right[i] = max(resRight, maxRight - prices[i]);
        }
        // 正序遍历，resLeft 代表截止到 i，prices 序列能赚的最大的钱
        int minLeft = INT_MAX;
        int resLeft = 0;
        for(int i=0;i<n;i++) {
            minLeft = min(prices[i], minLeft);
            resLeft = max(resLeft, prices[i] - minLeft);
            // resLeft + right[i] 代表以 i 为分割，两侧分别能赚到的钱的总和
            result = max(result, resLeft + right[i]);
        }
        return result;
    }
};