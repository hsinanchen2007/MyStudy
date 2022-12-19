### 解题思路一 动态规划
    /*
     * 方法1 动态规划 O(n^2)
     *
     * 定义dp[i]为考虑前i个元素，以第i个数字结尾的最长上升子序列的长度，其中nums[i]必须被包括在长度里面。
     * 从小到大计算dp[i]的值，dp[i]的值由dp[0...i-1]的值决定，所以动态规划的转移方程为：
     * dp[i] = max(dp[j]) + 1;    其中0 <= j < i，且nums[j] < nums[i]
     * 即当nums[j]小于nums[j]时，dp[i]的值为前面i个值的最长子序列长度加一。
     * 即考虑往dp[0…i−1]中最长的上升子序列后面再加一个nums[i]。
     * 由于dp[j]代表nums[0…j]中以nums[j]结尾的最长上升子序列，
     * 所以如果能从dp[j]这个状态转移过来，那么nums[i]必然要大于nums[j]，
     * 才能将nums[i]放在nums[j]后面以形成更长的上升子序列。
     * */
### 代码
```cpp
int lengthOfLIS(std::vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }

    if(nums.size() < 2){
        return nums.size();
    }

    // 状态数组
    std::vector<int> dp(nums.size(), 0);

    for (int i = 0; i < nums.size(); i++) {
        // 每个数的初始值为1
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            // 如果nums[j] < nums[i]就将dp[j]加一，
            // 即： dp[i] = dp[j] + 1
            if (nums[j] < nums[i]) {
                // 对dp[i]更新为当前子序列的最大值
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    // 返回状态数组的最大值
    return *std::max_element(dp.begin(), dp.end());
}
```

### 解题思路二 贪心算法+二分查找
    /*
     * 方法2 贪心算法+二分查找 O(nlogn)
     *
     * 贪心思路：要使上升子序列尽可能长，则需要让序列上升尽可能慢，
     * 依次每次在上升子序列后面加上的数尽可能小。
     *
     * 定义数组dp[]，保存最长上升子序列。
     * 对原序列进行遍历，将每一位元素二分插入到数组dp中，
     * 1. 如果dp中的元素都比当前的数大，就将它插到数组的末尾；
     * 2. 如果当前的数不比dp中所有数都大，则用它覆盖比它大的元素中最小的那个数。
     *
     * 按照贪心算法的思路，即为dp数组存储的是比较小的数，这样dp的长度就是最长子序列的长度。
     * */
### 代码
```cpp
int lengthOfLIS(std::vector<int> &nums) {
    if(nums.empty()){
        return 0;
    }

    if(nums.size() < 2){
        return nums.size();
    }

    // 定义最长子序列数组
    std::vector<int> dp;
    dp.push_back(nums[0]);

    // 遍历数组元素
    for(auto num : nums){
        // 如果当前数大于数组dp的所有数，
        // 则将该数存储到dp数组的末尾
        if(num > dp.back()){
            dp.push_back(num);
            continue;
        }

        // 如果当前数不大于数组dp的所有数，
        // 则对数组dp中的数进行二分查找，
        // 找到大于当前num的第一个数
        int left = 0, right = dp.size() - 1;
        while (left < right){
            int mid = left + (right - left)/2;
            if(dp[mid] < num){
                left = mid +1;
            } else{
                right = mid;
            }
        }
        // 将当前数覆盖dp数组中找到的第一个大于当前数的元素
        dp[left] = num;
    }

    // 返回最长子序列的长度
    return dp.size();
}
```