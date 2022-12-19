### 解题思路
无情的回溯，木得感情

### 代码

```cpp
class Solution {
public:
    bool flag = false;
    int key = 0;
    int kNum = 0;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int allCount = 0;
        for (int i : nums) {
            allCount += i;
        }
        if (nums.empty() || k == 0) {
            return false;
        }
        if (allCount % k != 0 ) {
            return false;
        }
        key = allCount / k;
        sort(nums.begin(), nums.end(), [](const int i1, const int i2){
            return i1 > i2;
        });
        kNum = k;
        vector<int> result;
        return dfs(nums, result);
    }
    bool dfs(vector<int>& num, vector<int>& result) {
        if (num.empty()) {
            for (int res : result) {
                if (res != key) {
                    return false;
                }
            }
            return true;
        }
        for (int i = 0; i < result.size(); i++) {
            if (num[0] + result[i] > key) {
                continue;
            }
            vector<int> newNum(num.begin() + 1, num.end());
            result[i] += num[0];
            if (dfs(newNum, result)) {
                return true;
            }
            result[i] -= num[0];
        }
        if (result.size() >= kNum) {
            return false;
        }
        result.push_back(num[0]);
        vector<int> newNum(num.begin() + 1, num.end());
        if (dfs(newNum, result)) {
            return true;
        }
        result.pop_back();
        return false;
    }
};
```