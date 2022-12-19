经典的智力游戏 翻灯问题

题目给出的输入空间非常小，尝试用暴力解，ac

第一行每个位置都有点或者不点 两种情况， 那么第一行一共有2^n种情况
只要第一行结果确定，后面每行的结果都确定了
最后点完之后check一下能不能全翻转，记录点击的数目即可


```C++
class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        vector<int> head(mat[0].size(), 0);
        int res = -1;
        dfs(mat, head, 0, res);
        return res;
    }
    
    void dfs(vector<vector<int>>& mat, vector<int> head, int start, int& res) {
        if (start > head.size()) return;
        int t = count(mat, head);
        if (t > -1) res = res == -1 ? t : min(res, t);
        for (int i = start; i < head.size(); ++i) {
            head[i] = 1 - head[i];
            dfs(mat, head, i + 1, res);
            head[i] = 1 - head[i];
        }
    }
    
    int count(vector<vector<int>> mat, const vector<int>& head) {
        int res = 0;
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[0].size(); ++j) {
                if ((i == 0 && head[j] == 1) || (i > 0 && mat[i - 1][j] == 1)) {
                    ++res;
                    mat[i][j] = 1 - mat[i][j];
                    if (i > 0) mat[i - 1][j] = 1 - mat[i - 1][j];
                    if (j > 0) mat[i][j - 1] = 1 - mat[i][j - 1];
                    if (j < head.size() - 1) mat[i][j + 1] = 1 - mat[i][j + 1];
                    if (i < mat.size() - 1) mat[i + 1][j] = 1 - mat[i + 1][j];
                }
            }
        }

        return check(mat) ? res : -1;
    }
    
    bool check(vector<vector<int>>& m) {
        for (auto& v : m) {
            for (auto& n : v) {
                if (n)
                    return false;
            }
        }
        return true;
    }
};
```