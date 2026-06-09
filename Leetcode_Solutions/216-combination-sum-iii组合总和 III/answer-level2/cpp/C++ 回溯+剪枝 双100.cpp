![捕获.PNG](https://pic.leetcode-cn.com/c7f3ca63f35654bca2837ef565e73ccc6521e1f23a0140cae6c5a80f7166ac6f-%E6%8D%95%E8%8E%B7.PNG)

```c++
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        BackTrack(k, n, 1);
        return res;
    }

private:
    void BackTrack(int k, int total, int beg) {
        if (k == 0) {
            if (total == 0) {
                res.push_back(path);
            }
            return;
        }
        for (int i = beg; i <= 9; i++) {
            if (i > total) break;//剪枝
            path.push_back(i);
            BackTrack(k-1, total-i, i+1);
            path.pop_back();
        }
    }

private:
    vector<vector<int>> res;
    vector<int> path;
};
```
