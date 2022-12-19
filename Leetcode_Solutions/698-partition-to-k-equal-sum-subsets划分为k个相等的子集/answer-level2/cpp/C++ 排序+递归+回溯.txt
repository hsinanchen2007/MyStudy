### 解题思路
1. 和值一定要能被k均分
2. 从大到小排序后，可以减少回溯的次数
3. 借鉴题解圈的大神的回溯算法，练习&学习中

### 代码

```cpp
class Solution {
public:
    bool backtrace(const vector<int>& nums, vector<int>& sums, int i, int k, int average)
    {
        if (i == nums.size()) {
            return true;
        }
        for (int j = 0; j < k; j++) {
            if (sums[j] < average && nums[i] + sums[j] <= average) {
                sums[j] += nums[i];
                if (backtrace(nums, sums, i + 1, k, average)){
                    return true;
                }
                sums[j] -= nums[i];
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k) {
            return false;
        }
        // 排序
        sort(nums.begin(), nums.end(), less<int>());
        vector<int> sums(k, 0);
        return backtrace(nums, sums, 0, k, sum / k);
    }
};
```