### 解题思路
本题类似背包问题，但是比背包问题简单得多，没有最大容量的限制。
对于每个位置的选择来讲，要么选该位置预约，要么下个位置预约。
选择本位置预约，只能选择下面的第两个位置进行预约。
所以每一个位置就是（选择本位置k+（k+2）位置的最大值）与（（k+1位置最大值））中较大的那个值。
边界条件为：当你选到最后一个位置，最大值就是自己，超出选择范围返回0.
get函数为递归版本 果不其然炸了

### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int n = nums.size();
        int dp[n];
        dp[n] = 0;
        dp[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        }
        return dp[0];
    }

    int get(vector<int> &nums, int k) {
        if (k == nums.size() - 1) return nums[k];
        if(k >= nums.size()) return 0;

        int res = 0;
        int res1 = nums[k] + get(nums, k + 2);
        int res2 = get(nums, k + 1);

        res = max(res1, res2);
        return res;
    }
};
```