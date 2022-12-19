```C++ []
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        int N = nums.size();
        int maxSum3 = nums[N - 3] + nums[N - 2] + nums[N - 1];
        int maxSum2 = nums[N - 2] + nums[N - 1];
        vector<vector<int> > res;
        for (int i = 0; i < N - 3; ++i) {
            if (4 * nums[i] > target) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] + maxSum3 < target) continue;
            for (int j = i + 1;j < N - 2; ++j) {
                if (2 * (nums[i] + nums[j]) > target) break;
                if (j > i + 1 && nums[j - 1] == nums[j]) continue;
                if (nums[i] + nums[j] + maxSum2 < target) continue;
                int t = target - nums[i] - nums[j];
                int l = j + 1;
                int r = N - 1;
                while (l < r) {
                    if (nums[l] + nums[r] > t) {
                        --r;
                    } else if (nums[l] + nums[r] < t) {
                        ++l;
                    } else {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[++l]);
                        while (l < r && nums[r] == nums[--r]);
                    }
                }
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/12553c9dbd6cea3e2168752fb8e6c67ab9632660fe6de947137f52842a7c128f-image.png)
