```
class Solution {
public:
    void helper(vector<int>& nums, int k, vector<vector<int> >& v) {
        if (k == nums.size()) return;
        int n = v.size();
        for (int i = 0; i < n; ++i) {
            if (v[i].back() <= nums[k]) {
                auto u = v[i];
                u.push_back(nums[k]);
                v.push_back(u);
            }
        }
        v.push_back({nums[k]});
        helper(nums, k + 1, v);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int> > v;
        helper(nums, 0, v);
        sort(v.begin(), v.end());
        vector<vector<int> > res;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i].size() < 2) continue;
            if (i > 0 && v[i] == v[i - 1]) continue;
            res.push_back(v[i]);
        }
        return res;
    }
};
```


![image.png](https://pic.leetcode-cn.com/902f45556ea22b149b49ceabf748ad63a9915bce928668fd99a7d023091955e8-image.png)
