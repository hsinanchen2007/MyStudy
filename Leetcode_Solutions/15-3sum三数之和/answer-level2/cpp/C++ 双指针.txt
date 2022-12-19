```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> r;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // 1, 2, 3
            if (nums[i] > 0) break;
            // 1, 1, 2
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int s = nums[i] + nums[j] + nums[k];
                if (s == 0) {
                    vector<int> v{nums[i], nums[j], nums[k]};
                    if (r.empty() || r.back() != v) {
                        r.emplace_back(move(v));
                    }
                    j++;
                    k--;
                } else if (s < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return r;
    }
};
```