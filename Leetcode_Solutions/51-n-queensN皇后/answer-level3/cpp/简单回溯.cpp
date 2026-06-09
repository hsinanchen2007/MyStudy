### 解题思路
就是简单的回溯，从第0行到第n-1行开始递归，这样不用考虑行冲突，然后用三个bool数组分别标记列、正对角线和反对角线，不冲突再继续向下递归，直到最后一行以后把解记录下来。

### 代码

```cpp
class Solution {
public:
    void f(vector<vector<string>>& result, vector<string>& s, bool* mark_col, bool* mark_zheng, bool* mark_fan, int row, int n)
    {
        if (row == n)
        {
            result.push_back(s);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (!mark_col[i] && !mark_zheng[row - i + n - 1] && !mark_fan[row + i])
            {
                mark_col[i] = true;
                mark_zheng[row - i + n - 1] = true;
                mark_fan[row + i] = true;
                s[row][i] = 'Q';
                f(result, s, mark_col, mark_zheng, mark_fan, row + 1, n);
                s[row][i] = '.';
                mark_fan[row + i] = false;
                mark_zheng[row - i + n - 1] = false;
                mark_col[i] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        bool *mark_col = new bool[n];
        bool *mark_zheng = new bool[2 * n - 1];
        bool *mark_fan = new bool[2 * n - 1];
        vector<string> s;

        for (int i = 0; i < n; i++)
        {
            mark_col[i] = false;
            string tmp = "";
            for (int j = 0; j < n; j++)
                tmp += '.';
            s.push_back(tmp);
        }
        for (int i = 0; i < 2 * n - 1; i++)
        {
            mark_zheng[i] = false;
            mark_fan[i] = false;
        }
        
        f (result, s, mark_col, mark_zheng, mark_fan, 0, n);

        delete []mark_fan;
        delete []mark_zheng;
        delete []mark_col;

        return result;
    }
};
```