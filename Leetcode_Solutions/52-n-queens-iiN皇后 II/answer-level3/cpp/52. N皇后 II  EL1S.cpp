[51题](https://leetcode-cn.com/problems/n-queens/solution/51-nhuang-hou-el1s-by-el1s/)求N皇后的解，这道题只要求有多少个解，不用求出来是哪一些解。

我们把51题的稍微改一下就可以了
```
class Solution {
    vector<vector<string>> res;
    int n;
    void dfs(vector<bool>& col, vector<bool>& dig, vector<bool>& udig, vector<string>& v, int rownum)
    {
        if(rownum == n)
        {
            res.push_back(v);
            return;
        }
        for(int j = 0; j < n; j++)
        {
            if(col[j] || dig[j - rownum + n] || udig[j + rownum])
                continue;
            v[rownum][j] = 'Q';
            col[j] = dig[j - rownum + n] = udig[j + rownum] = true;
            dfs(col, dig, udig, v, rownum + 1);
            col[j] = dig[j - rownum + n] = udig[j + rownum] = false;
            v[rownum][j] = '.';
        }
    }
public:
    int totalNQueens(int _n) {
        n = _n;
        int N = 2*n;
        vector<bool> col(n,false), dig(N, false), udig(N, false);
        vector<string> v(n, string(n, '.'));
        dfs(col, dig, udig, v, 0);
        return res.size();
    }
};
```
还可以进行优化
```
class Solution {
    int res;
    int n;
    void dfs(vector<bool>& col, vector<bool>& dig, vector<bool>& udig, int rownum)
    {
        if(rownum == n)
        {
            res++;
            return;
        }


        for(int j = 0; j < n; j++)
        {
            if(col[j] || dig[j - rownum + n] || udig[j + rownum])
                continue;
            col[j] = dig[j - rownum + n] = udig[j + rownum] = true;
            dfs(col, dig, udig, rownum + 1);
            col[j] = dig[j - rownum + n] = udig[j + rownum] = false;
        }
    }
public:
    int totalNQueens(int _n) {
        n = _n;
        vector<bool> col(n,false), dig(2*n, false), udig(2*n, false);
        dfs(col, dig, udig, 0);
        return res;
    }
};
```

