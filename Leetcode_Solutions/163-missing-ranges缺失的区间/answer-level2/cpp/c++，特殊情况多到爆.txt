使用long long扩大范围
```
class Solution {
public:
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        vector<string> res;
        int size = nums.size();
        long long left = (long long)lower - 1;
        long long val;
        for (int i = 0; i < size; ++i) {
            val = nums[i] - left;
            if (val == 2) {
                res.push_back(to_string(nums[i] - 1));
            } else if (val > 2) {
                res.push_back(to_string(left + 1) + "->" + to_string(nums[i] - 1));
            }
            left = nums[i];
        }
        val = upper - left;
        if (val == 1) {
            res.push_back(to_string(upper));
        } else if (val > 1) {
            res.push_back(to_string(left + 1) + "->" + to_string(upper));
        }
        return res;
    }
};
```