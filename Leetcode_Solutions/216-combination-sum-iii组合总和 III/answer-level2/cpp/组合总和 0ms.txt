### 解题思路
回溯法， 时间复杂度O(9! / (9 - k)!)

### 代码

```cpp
class Solution {
public:
    void combinationSum3Help(int k, int n, int st, vector<int> &combinations, vector<vector<int>> &res) {
        if (k == 0 && n == 0) {
            res.push_back(combinations);
            return;
        }
        if (k == 0 && n != 0) {
            return;
        }
        for (int i = st; i <= 9; i++) {
            combinations.push_back(i);
            combinationSum3Help(k - 1, n - i, i + 1, combinations, res);
            combinations.pop_back();
        }
    }
};
```