解空间是一个二叉树，每个节点分为选择i和不选i两个分支

```
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combine(int n, int k) {
        if (n < k) return result;
        vector<int> arr(k, 0);
        combine(n, k, 0, 0, arr);
        return result;
    }
    void combine(int n, int k, int n_pos, int k_pos, vector<int>& arr) {
        if (n - n_pos < k - k_pos) return;
        if (k_pos == k) {
            result.emplace_back(arr);
            return;
        }
        arr[k_pos] = n_pos + 1;                  // 注意数字是从1开始
        combine(n, k, n_pos + 1, k_pos+1, arr);  // 选择n_pos的分支
        combine(n, k, n_pos + 1, k_pos, arr);    // 不选择n_pos的分支
    }
};
```
