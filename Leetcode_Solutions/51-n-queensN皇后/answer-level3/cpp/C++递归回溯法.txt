回溯递归法，核心数据结构是使用一个vector即可记录整个棋盘的皇后位置，依据是第i行有且只会有一个皇后，在j位置，即v[i]=j
```c
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> vvs; // 返回值
        vector<int> v; // v[i] = j, 表示第i行皇后在第j列，n皇后限制一行只能有一个皇后
        v.resize(n);
        findQueue(n, 0, vvs, v);
        return vvs;
    }
    void findQueue(int n, int i, vector<vector<string>>& vvs, vector<int>& v)
    {
        if(i >= n)//如果找到了第n行（从0行开始），说明0~n-1行都已经找到了合适的位置，当前v即为一个有效解
        {
            vector<string> vs;
            for(int j = 0; j < n; j++)
            {
                string s;
                s.resize(n,'.');
                s[v[j]] = 'Q';
                vs.push_back(s);
            }
            vvs.push_back(vs);
            return;//找到了一个有效解，返回到上层，继续寻找下一个解
        }
        for(int j=0; j<n; j++)//试探当前行每一个位置
        {
            if(checkSuccess(n, i, j, v))//检查该位置能否满足要求，满足则记录该位置，继续查找下一行的皇后位置
            {
                v[i] = j;
                findQueue(n, i+1, vvs, v);
            }
            // else 不满足要求，则直接返回到上层，寻找有效解
        }
    }

    bool checkSuccess(int n, int i, int j, vector<int>& v)
    {
        for(int k = 0; k < i; k++)
        {
            if(v[k] == j)//在同一列
            {
                return false;
            }
        }
        for(int k = i - 1, m = j - 1; k >= 0 && m >= 0; k--, m--)
        {
            if(v[k] == m)//在同一\
            {
                return false;
            }
        }
        for(int k = i - 1, m = j + 1; k >=0 && m < n; k--, m++)
        {
            if(v[k] == m)//在同一/
            {
                return false;
            }
        }
        return true;//满足要求
    }
};
```
