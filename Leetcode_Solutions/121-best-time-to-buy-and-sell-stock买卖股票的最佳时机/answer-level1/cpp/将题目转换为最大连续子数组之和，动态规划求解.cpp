假设我们在第i天买入，第j (j > i)天卖出股票，获得的利润是prices[j] - prices[i].
记j - i = k，那么由于数学关系式可知：

**prices[j] - prices[i] = (prices[j] - prices[i+k-1]) + (prices[i+k-1] - prices[i+k-1]) +  .... +  (prices[i+1] -  prices[i])**

那么知道每一个prices[i+1] -  prices[i]后本题求max(prices[j] - prices[i])可以转换为求最大连续子数组和的问题

如股票价格为[7,1,5,3,6,4]，则可以转换为求数组[-6, 4, -2, 3, -2]的最大连续子数组之和。

同第53题：[https://leetcode-cn.com/problems/maximum-subarray/](https://leetcode-cn.com/problems/maximum-subarray/)

```
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1)
        {
            return 0;
        }

        int size = prices.size() - 1;
        for (int i = 0; i < size; i++) {
            prices[i] = prices[i + 1] - prices[i];
        }
        int res = maxSubArray(prices, size);
        return (res > 0) ? res : 0;
    }

    int maxSubArray(vector<int> &nums, int right) {
        int res = nums[0];

        for (int i = 1; i < right; i++) {
            if (nums[i - 1] > 0) {
                nums[i] += nums[i - 1];
            }
            res = max(res, nums[i]);
        }

        return res;
    }
};
```
