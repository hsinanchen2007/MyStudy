```
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        long tgt = target;
        long del = LONG_MAX;
        long res = 0;
        for (int i = 0; i < N - 2; ++i) {
            long v = nums[i];
            int l = i + 1;
            int r = N - 1;
            while (l < r) {
                long vl = nums[l];
                long vr = nums[r];
                if (v + vl + vr == tgt) return tgt;
                if (abs(v + vl + vr - tgt) < del) {
                    res = v + vl + vr;
                    del = abs(res - tgt);
                }
                if (v + vl + vr < tgt) {
                    ++l;
                } else {
                    --r;
                }
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/493f655e46485cc192a215c766861db55c2a4c703a18eb9c189f38d1291ba048-image.png)
