```
class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        if (nums.size() < 4)
            return {};
        sort(nums.begin(), nums.end());
        set<vector<int>> set;
        int i = 0;
        while (i < nums.size() - 3) {
            int j = i + 3;
            while (j < nums.size()) {
                int l = i + 1;
                int r = j - 1;
                int complement = target - nums[i] - nums[j];
                while (l < r) {
                    int sum = nums[l] + nums[r];
                    if (sum == complement) {
                        vector<int> quad = {nums[i], nums[l], nums[r], nums[j]};
                        set.insert(quad);
                        while (l < j && nums[l] == quad[1])
                            l++;
                        while (r > i && nums[r] == quad[2])
                            r--;
                    } else if (sum > complement)
                        r--;
                    else
                        l++;
                }
                j++;
            }
            i++;
        }
        return vector<vector<int>>(set.begin(), set.end());
    }
};
```
