```c++
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> r;
        int n = nums.size();
        permute(r, nums, 0, n - 1);
        return r;
    }

    void permute(vector<vector<int>>& result, vector<int>& nums, int left, int right) {
        if (left >= right) {
            result.push_back(nums);
            return;
        }
        for (int i = left; i <= right; i++) {
            swap(nums[i], nums[left]);
            permute(result, nums, left + 1, right);
            swap(nums[i], nums[left]);
        }
    }
};
```