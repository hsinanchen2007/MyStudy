### 解题思路
排序后必须比前一个大就行

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if (A.empty()) return 0;
        sort(A.begin(), A.end());
        int ans = 0;
        for (size_t i = 1; i < A.size(); i ++) {
            if (A[i] > A[i-1]) continue;
            int t = A[i];
            A[i] = max(A[i-1], A[i]) + 1;
            ans += A[i] - t;
        }
        return ans;
    }
};
```