```c++
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        const int n = nums.size();
        int i = 0, j = 1;
        for (int i = 0; i <= n - 4; ++i) {
            if (4 * nums[i] > target) break;
            while (i >= 1 && i <= n - 4 && nums[i] == nums[i - 1]) ++i;
            for (int j = i + 1; j <= n - 3; ++j) {
                if (2 * (nums[i] + nums[j]) > target) break;
                while (i + 1 != j && j >= 2 && j <= n - 3 && nums[j] == nums[j - 1]) ++j;
                int low = j + 1, high = n - 1;
                while (low < high) {
                    //cout << "low = " << low << "high = " << high << endl;
                    int s = nums[low] + nums[high];
                    if (nums[i] + nums[j] + s == target) {
                        ans.push_back({nums[i], nums[j], nums[low], nums[high]});
                        while (low < high && nums[high] == nums[high - 1])
                            --high;
                        --high;
                        while (low < high && nums[low] == nums[low + 1])
                            ++low;
                        ++low;
                    }
                    else if (nums[i] + nums[j] + s < target)
                        ++low;
                    else --high;
                }
            }
        }
        return ans;
    }
};
```
复杂度为$O(n^3)$