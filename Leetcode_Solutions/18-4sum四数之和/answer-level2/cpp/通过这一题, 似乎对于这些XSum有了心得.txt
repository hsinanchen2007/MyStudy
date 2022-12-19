关键点就在于如何筛掉重复的结果.

下面这个代码未必是最优的(因为某些情况下可以直接跳出), 但是感觉使用起来还是十分直观

```c++
class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;  // 将所有略过重复值都抽象成这样的continue
            }
            for (int j = i + 1; j < nums.size(); j++) {
                if (j != i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                for (int start = j + 1, end = nums.size() - 1; start < end;) {
                    int total = nums[i] + nums[j];

                    total += nums[start] + nums[end];
                    if (total == target) {
                        if (start != j + 1 && nums[start] == nums[start - 1]) {
                            start += 1;
                            continue;
                        }
                        if (end != nums.size() - 1 && nums[end] == nums[end + 1]) {
                            end -= 1;
                            continue;
                        }
                        res.push_back({nums[i], nums[j], nums[start], nums[end]});
                        start += 1; // 这里容易忘记
                    } else if (total > target) {
                        end -= 1;
                    } else {
                        start += 1;
                    }
                }
            }
        }
        return res;
    }
};
```