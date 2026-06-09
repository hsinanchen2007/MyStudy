
### 代码

```cpp
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        int ans = 0;
        vector<unordered_map<long, int>> helper(n);
        for (int i = 1; i < n - 1; i++) {
            for (int j = 0; j < i; j++) {
                long diff = (long)A[i] - (long)A[j];
                if (helper[j].count(diff)) {
                    ans += helper[j][diff];
                    helper[i][diff] += helper[j][diff] + 1;
                } else {
                    helper[i][diff]++;
                }
            }
        }
        for (int j = 0; j < n - 1; j++) {
            long diff = (long)A[n - 1] - (long)A[j];
            if (helper[j].count(diff)) {
                ans += helper[j][diff];
            }
        }
        return ans;
    }
};
```