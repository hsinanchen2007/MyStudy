![image.png](https://pic.leetcode-cn.com/01850b5da7b52d03126eee6209db3e140949bd3504d15a1aea73c17a0f4c58f0-image.png)

### 解题思路
给定数组不含重复元素、使用时也不能重复使用的组合问题。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;

    void backtrack(int n, int k, int start, vector<int> combination, vector<bool>& marked) {
        if (k == 0 && n == 0) {
            res.push_back(combination);
            return;
        }
        if (n < 0) return;
        for (int i = start; i < 10; ++i) {
            if (i <= n) {
                if (marked[i]) continue;
                combination.push_back(i);
                marked[i] = true;
                backtrack(n - i, k - 1, i + 1, combination, marked);
                marked[i] = false;
                combination.erase(combination.end() - 1);
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<bool> marked(10, false);
        vector<int> combination;
        backtrack(n, k, 1, combination, marked);
        return res;
    }
};
```