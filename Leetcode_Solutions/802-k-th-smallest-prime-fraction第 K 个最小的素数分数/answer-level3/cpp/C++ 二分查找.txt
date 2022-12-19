1，浮点数二分查找，先找到满足条件的的浮点值`d`，使得小于`d`的分数个数为`k`个
2，找到`p`和`q`使得`p/q`小于`d`且与`d`最接近就是答案

```
class Solution {
public:
    int count(const vector<int>& nums, double d) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res += nums.end() - upper_bound(nums.begin() + i + 1, nums.end(), nums[i] / d);
        }
        return res;
    }
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        double lo = 0.0;
        double hi = 1.0;
        while (lo < hi) {
            double mid = lo + (hi - lo) / 2;
            int cnt = count(A, mid);
            if (cnt == K) {
                lo = hi = mid;
                break;
            }
            if (cnt < K) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        double d = lo;
        // 找到p、q使得p/q大于d且最接近d
        int p = 1;
        int q = A.back();
        for (int i = 0; i < A.size(); ++i) {
            int tp = A[i];
            auto it = upper_bound(A.begin() + i + 1, A.end(), A[i] / d);
            if (it != A.end()) {
                int tq = *it;
                double td = 1.0 * tp / tq;
                if (td < d && d - td < d - 1.0 * p / q) {
                    p = tp;
                    q = tq;
                }
            }
        }
        return {p, q};
    }
};
```

![image.png](https://pic.leetcode-cn.com/10ccbfbc367704d6a3a574628a788bfa9e279762c9107cb92b76b5c6697324fc-image.png)
