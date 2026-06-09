边界情况太多，折磨地浑身难受
```
class Solution {
public:
    int bisearch(vector<int>& nums, int t) {
        if (nums.empty() || nums[0] > t) return -1;
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l + 1) / 2;
            if (nums[m] <= t) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        return l;
    }
    string trans(long l, long r) {
        if (l == r) return to_string(l);
        return to_string(l) + "->" + to_string(r);
    }
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if (nums.empty()) return {trans(lower, upper)};
        int N = nums.size();
        int k = bisearch(nums, lower);
        vector<string> res;
        long t = lower;
        if (k != -1 && nums[k] == lower) ++t;
        for (int i = k; i + 1 < N && (i == -1 || nums[i] <= upper); ++i) {
            long t1 = min(nums[i + 1] - 1, upper);
            if (t <= t1) res.push_back(trans(t, t1));
            t = t1 + 2;
        }
        if (t <= upper) res.push_back(trans(t, upper));
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/b88a23da802b9e260b6d6dea61f997ba5dc4df520f2a572a5f2dfbec031da070-image.png)
