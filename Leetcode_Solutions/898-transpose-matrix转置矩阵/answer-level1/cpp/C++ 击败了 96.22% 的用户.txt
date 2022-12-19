![1.png](https://pic.leetcode-cn.com/44198aea12affc04edf2eeb24d51fcb7d5e207ec0b7ef0c8f3398f4aa0396d48-1.png)

### 代码
```cpp
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int ro = A.size();
        int co = A[0].size();

        vector<vector<int>> res(co);
        for (int i = 0; i < co; ++i) {
            for (int j = 0; j < ro; ++j)
                res[i].emplace_back(A[j][i]);
        }
        return res;
    }
};
```