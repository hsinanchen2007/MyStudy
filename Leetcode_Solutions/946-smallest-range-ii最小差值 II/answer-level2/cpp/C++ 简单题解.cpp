```
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int N = A.size();
        int res = A[N - 1] - A[0];
        for (int i = 0; i < N - 1; ++i) {
            int mx = max(A[N - 1], A[i] + 2 * K);
            int mn = min(A[0] + 2 * K, A[i + 1]);
            res = min(res, mx - mn);
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/a6a06caccd34ac91fc58b7ed85f35afe8ea6a404438d67640561696436bbb290-image.png)
