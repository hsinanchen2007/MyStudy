### 解题思路一 贪心法
    /*
     * 方法一 贪心法 O(n)
     *
     * 当叠加的和小于0时，就从下一个数重新开始，
     * 同时更新最大和的值(最大值可能为其中某个值)，
     * 当叠加和大于0时，将下一个数值加入和中，
     * 同时更新最大和的值，依此继续。
     *
     * 举例： nums = [-2,1,-3,4,-1,2,1,-5,4]
     * sum = INT_MIN <= 0-> sum = -2 <= 0 -> sum = 1 > 0 ->
     * -> sum = -2 <= 0 -> sum = 4 > 0 -> sum = 3 > 0 ->
     * -> sum = 5 > 0 -> sum = 6 > 0 -> sum = 1 > 0 ->
     * -> sum = 5 > 0
     * res = [-2, 1, 1, 4, 4, 5, 6, 6, 6]
     * 最终返回 res = 6
     * */
### 代码

```cpp
int Solution42::maxSubArray(std::vector<int> &nums) {
    assert(!nums.empty());

    int resSum = INT_MIN;
    int curSum = 0;

    // 遍历数组
    for (int i = 0; i < nums.size(); i++) {
        // 当sum小于0时，就从下一个数重新开始
        // 同时更新每次叠加的最大值
        if (curSum <= 0) {
            curSum = nums[i];
        } else {
            // 和大于0时
            curSum += nums[i];
        }

        // 不断更新子串的最大值
        if (curSum > resSum) {
            resSum = curSum;
        }
    }

    return resSum;
}
```

### 解题思路二 分治法
    /*
     * 方法二 分治法 O(nlogn)
     *
     * 分治法模板：
     * 1. 定义基本情况
     * 2. 将问题分解为子问题并递归解决子问题
     * 3. 合并子问题的解以获得原始问题的解
     *
     * 将nums由中点mid分为三种情况：
     * 1. 最大子串在左边
     * 2. 最大子串在右边
     * 3. 最大子串跨中点，左右都有
     *
     * 当子串在左边或右边时，继续分中点递归分解到一个数为止，
     * 对于递归后横跨的子串，再分治为左侧和右侧求最大子串，
     * 可使用贪心算法求最大子串值，再合并为原始的最大子串值
     * */
### 代码

```cpp
int maxSubArray2(std::vector<int> &nums) {
    assert(!nums.empty());

    return helper(nums, 0, nums.size() - 1);
}

int helper(std::vector<int> &nums, int left, int right) {
    // 分解到一个值时返回该值
    if (left == right) {
        return nums[left];
    }

    // 求中点值
    int mid = left + (right - left) / 2;

    // 中点左边的最大值
    int leftSum = helper(nums, left, mid);
    // 中点右边的最大值
    int rightSum = helper(nums, mid + 1, right);
    // 横跨中点的最大值
    int croSum = crossSum(nums, left, right, mid);

    // 返回以上三种情况中的最大值
    return std::max(std::max(leftSum, rightSum), croSum);
}

int crossSum(std::vector<int> &nums, int left, int right, int mid) {
    // 分解到一个值时返回该值
    if (left == right) {
        return nums[left];
    }

    // 贪心法求左边的最大值
    int leftSubsum = INT_MIN;
    int curSum = 0;
    for (int i = mid; i > left - 1; i--) {
        curSum += nums[i];
        leftSubsum = std::max(leftSubsum, curSum);
    }

    // 贪心法求右边的最大值
    int rightSubsum = INT_MIN;
    curSum = 0;
    for (int i = mid + 1; i < right + 1; i++) {
        curSum += nums[i];
        rightSubsum = std::max(rightSubsum, curSum);
    }

    return leftSubsum + rightSubsum;
}
```

### 解题思路三 动态规划法
    /*
     * 方法三 动态规划—— Kadane算法 O(n)
     *
     * 在整个数组或在固定大小的滑动窗口中找到总和或最大值或最小值的问题，
     * 可通过动态规划(DP)在线性时间内解决
     *
     * 两种标志DP适用于数组：
     * 1. 常数空间，沿数组移动并子啊原数组修改；
     * 2. 线性空间，首先沿left->right方向移动，然后沿right->left方向移动，最后合并结果。
     *
     * 本题可通过修改数组跟踪当前位置的最大和，
     * 在知道当前位置的最大和后更新全局最大和。
     * */
### 代码

```cpp
int maxSubArray3(std::vector<int> &nums) {
    assert(!nums.empty());

    int n = nums.size();
    int maxSum = nums[0];

    // 如果当前值小于0，
    // 重新开始(全局最大值更新)
    for (int i = 1; i < n; i++) {
        // 更新当前的最大值
        if (nums[i - 1] > 0) {
            nums[i] += nums[i - 1];
        }
        // 更新全局的最大值
        maxSum = std::max(nums[i], maxSum);
    }

    return maxSum;
}
```