### 解题思路
1、此处因为有负数的存在，所以一定要保存最小值，才可以进行下一步计算；
2、保存最小值和最大值；
3、获取转移矩阵：
maxDp[i+1] = max{nums[i+1], maxDp[i]*nums[i+1], minDp[i]*nums[i+1]}
minDp[i+1] = min{nums[i+1], minDp[i]*nums[i+1], maxDp[i]*nums[i+1]}
4、每次计算完，保存下当前的maxCount；
### 代码

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // maxDp[i+1] = max{nums[i+1], maxDp[i]*nums[i+1], minDp[i]*nums[i+1]}
        // minDp[i+1] = min{nums[i+1], minDp[i]*nums[i+1], maxDp[i]*nums[i+1]}
        // dp[i+1] = max(dp[i], dp[i+1])
        if (nums.empty() || nums.size() == 0) {
            return 0;
        }
        int dp = nums[0];
        int maxDp = nums[0];
        int minDp = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int tmp = maxDp; //存储变量
            maxDp = max(max(maxDp*nums[i], minDp* nums[i]), nums[i]);
            minDp = min(min(tmp*nums[i], minDp* nums[i]), nums[i]);
            dp = max(dp, maxDp);
        }
        return dp;
    }
};
```