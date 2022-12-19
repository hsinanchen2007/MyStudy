### 解题思路
    /*
     * 动态规划
     *
     * 动态规划的核心是找到状态转移方程。
     * 第n个预约的最大时长dp[n]是由第n-1个或第n-2个决定的。
     * 1. 如果接第n个预约电话，由于相邻的预约不能接，所以dp[n] = dp[n-2] + nums[n];
     * 2. 如果不接第n个预约，则dp[n] = dp[n-1]
     * 所以状态转移方程是： dp[i] = std::max(dp[i-1], dp[i-2] + nums[i])
     * */
### 代码

```cpp
int massage(std::vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }

    if (nums.size() == 1) {
        return nums[0];
    }

    // 状态保存数组
    std::vector<int> dp(nums.size(), 0);

    // 初始化初始状态的值
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);

    // 遍历数组，使用状态转移方程计算第n个预约的最大时长
    for (int i = 2; i < nums.size(); i++) {
        dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[nums.size() - 1];
}
```

### 优化
    /*
     * 动态规划优化
     *
     * 由上面动态规划的状态转移方程可知，i只依赖于i-1和i-2两个状态，
     * 所以可以将数组dp[]压缩为两个变量a,b来定义，其中a存储i-1，b存储i-2，
     * 这样空间复杂度就能降低到O(1)。
     * */
### 代码

```cpp
int massage2(std::vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }

    if (nums.size() == 1) {
        return nums[0];
    }

    int a = 0, b = 0;

    // a = dp[i-1]
    // b = dp[i-2]
    for (int num : nums) {
        int c = std::max(b, a + num);
        // 更新a和b的值，相当于a,b向右移
        a = b;
        b = c;
    }

    return b;
}

```