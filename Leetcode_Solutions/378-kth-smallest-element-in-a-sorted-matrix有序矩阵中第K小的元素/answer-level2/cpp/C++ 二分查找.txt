```C++ []
class Solution {
public:
    int count(const vector<vector<int>>& matrix, const vector<int> first_col, int num) {
        int res = 0;
        int r = lower_bound(first_col.begin(), first_col.end(), num + 1) - first_col.begin() - 1;
        for (int i = 0; i <= r; ++i) {
            res += lower_bound(matrix[i].begin(), matrix[i].end(), num + 1) - matrix[i].begin();
        }
        return res;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return -1;
        int N = matrix.size();
        vector<int> first_col;
        for (int i = 0; i < N; ++i) {
            first_col.push_back(matrix[i][0]);
        }
        int lo = matrix.front().front();
        int hi = matrix.back().back();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int cnt = count(matrix, first_col, mid);
            if (cnt < k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};
```

![image.png](https://pic.leetcode-cn.com/2f34aa4e76e82f0892204e449f66a7521cc30f5b0298d43ca73c29b71d3b3a30-image.png)
