### 解题思路
dfs比dp快

### 代码

```cpp
#if 0
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1) {
            return false;
        }

        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }

        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;

        vector<bool> dp(target + 1, false);

        dp[0] = true;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = target; j >= nums[i]; --j) {
                if (dp[target] == true) {
                    return true;
                }

                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

        return dp[target];
    }
};
#endif

class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1 != 0) {
            return false;
        }

        int target = sum / 2;

        sort(nums.rbegin(), nums.rend());

        if (nums.front() > target) {
            return false;
        }

        if (nums.front() == target) {
            return true;
        }

        return dfs(nums, 0, target);
    }
private:
    bool dfs(vector<int>& nums, int index, int target)
    {
        if (target == 0) {
            return true;
        } else if (target < 0 || index == nums.size()) {
            return false;
        } else {
            return dfs(nums, index + 1, target - nums[index]) || dfs(nums, index + 1, target);
        }
    }
};
```