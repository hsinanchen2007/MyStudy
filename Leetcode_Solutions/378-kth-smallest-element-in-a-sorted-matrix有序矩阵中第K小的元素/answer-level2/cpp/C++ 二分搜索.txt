```
class Solution {
public:
    int bisearch(vector<int>& v, int t) {
        int l = 0;
        int r = v.size() - 1;
        while (l < r) {
            int m = l + (r - l + 1) / 2;
            if (v[m] <= t) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        return l;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return -1;
        int R = matrix.size();
        int C = matrix[0].size();
        int low = matrix[0][0];
        int high = matrix[R - 1][C - 1];
        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (int i = 0; i < R; ++i) {
                if (matrix[i][0] <= mid) {
                    count += bisearch(matrix[i], mid) + 1;
                } else {
                    break;
                }
            }
            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return high;
    }
};
```
![image.png](https://pic.leetcode-cn.com/3eb1d9bf4734effca3d376dad303cce80462c16fb79db214a6fbca68aa53ca02-image.png)
