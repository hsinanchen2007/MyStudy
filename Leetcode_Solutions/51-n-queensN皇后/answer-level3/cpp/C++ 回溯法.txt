最经典的回溯算法问题
代码如下：
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
    void backtrace(int n, vector<int>& cols, vector<vector<int> >& res) {
        if (!valid(n, cols)) return;
        if (cols.size() == n) {
            res.push_back(cols);
            return;
        }
        for (int i = 0; i < n; ++i) {
            cols.push_back(i);
            backtrace(n, cols, res);
            cols.pop_back();
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> cols;
        vector<vector<int> > all;
        backtrace(n, cols, all);
        vector<vector<string> > res;
        for (auto& v : all) {
            vector<string> s;
            for (auto& c : v) {
                string t(n, '.');
                t[c] = 'Q';
                s.push_back(t);
            }
            res.push_back(s);
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/c787e6d7de99c8a0eec83c036634dcf8f5b47943fc6aed6c10eef80c2a1ae3ab-image.png)
