### 解题思路
思路1：（错误想法）最开始一直不知道如何处理``nums[0]``和``nums[n - 1]``，还打算另开一个``bool``型数组``flag[]``辅助``dp[]``数组记录有没有用到``nums[0]``，并在后续更新的时候将此标记继承下来（如何继承呢？就是如果``max（dp[i - 2], dp[i - 3]）== dp[i - 2]``时，``flag[i] = flag[i - 2]``,``i - 3``同理）。这种方法看似没有问题，提交上去也可以通过66/74个测例，但是有个问题在于：如果``dp[i - 2] == dp[i - 3]``，``flag[i]``没有一个固定的选择策略，导致错误。

思路2：既然头和尾最多只能偷一个，那么为什么不在一开始就分类讨论呢？即去头和去尾。再取最大值即为答案。

P.S. 我的代码中动态转移方程和其他题解略有不同，是因为这里``dp[i]``表示的是偷的最后一家为``nums[i]``时，和的最大值。所以动态转移方程为``dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i], i ≥ 3``

### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)    return 0;
        if(n == 1)    return nums[0];
        if(n == 2)    return max(nums[0], nums[1]);
        if(n == 3)    return max(nums[0], max(nums[1], nums[2]));
        vector<int> sub1(nums.begin(), nums.end() - 1), sub2(nums.begin() + 1, nums.end());
        return max(rob198(sub1), rob198(sub2)); 
    }
    int rob198(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return 0;	// 不可忽略的边界条件！
        if(n == 1) return nums[0];
        else if(n == 2)	return max(nums[0], nums[1]);
        else if(n == 3)	return  max(nums[0] + nums[2], nums[1]);
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[0] + nums[2];
        for(int i = 3; i < n; i++) {
            dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i];
        }
        return max(dp[n - 1], dp[n - 2]);
    }
};
 

```
![图片.png](https://pic.leetcode-cn.com/b34f9803a0f63001f15ef738e1e7e26e8adfc3bff4e99b25f4e9b20b1d6c9d33-%E5%9B%BE%E7%89%87.png)
