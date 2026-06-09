### 解题思路
1，构建单调数据，保证从大到小
2，凡是遇到不符合单调的数则二分查找寻求最远的小于等于该值的下标

### 代码

```cpp
class Solution {
public:
    int bisearch(const vector<int>& A, vector<int>& indices, int t) {
        int l = 0;
        int r = indices.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (A[indices[m]] > t) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return indices[l];
    }
    int maxWidthRamp(vector<int>& A) {
        if (A.empty()) return 0;
        int res = 0;
        vector<int> prefix{0};
        int N = A.size();
        for (int i = 1; i < N; ++i) {
            if (A[prefix.back()] > A[i]) {
                prefix.push_back(i);
            } else {
                int k = bisearch(A, prefix, A[i]);
                res = max(res, i - k);
            }
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/8f2042724ce7118be4daabb7026b916c8bd551dff430847b438b850ec81c8637-image.png)
