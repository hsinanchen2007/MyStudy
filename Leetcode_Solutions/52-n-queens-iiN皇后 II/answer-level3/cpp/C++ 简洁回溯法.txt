回溯算法最经典的问题之一
思路简单，代码如下：
```
class Solution {
public:
    bool valid(int n, vector<int>& cols) {
        if (cols.size() <= 1) 
            return true;
        int row = cols.size() - 1;
        int col = cols.back();
        for (int r = 0; r < row; ++r) {
            int c = cols[r];
            if (c == col || abs(c - col) == abs(r - row)) 
                return false;
        }
        return true;
    }
    void backtrace(int n, vector<int>& cols, int& res) {
        if (!valid(n, cols)) return;
        if (cols.size() == n) {
            ++res;
            return;
        }
        for (int i = 0; i < n; ++i) {
            cols.push_back(i);
            backtrace(n, cols, res);
            cols.pop_back();
        }
    }
    int totalNQueens(int n) {
        vector<int> cols;
        int res = 0;
        backtrace(n, cols, res);
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/a038a5331ee35c070be0d8cc7e8d2e0d834661384c4e2bad397800d4fca82254-image.png)
