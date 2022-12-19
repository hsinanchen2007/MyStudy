回溯退出条件：同列 正对角线 斜对角线


class Solution {
public:
    bool isOk(int row, int col)
    {         
        for(int i=0; i<pos.size(); i++)
        {
            if (pos[i] == col || row+col == i+pos[i] || row-col == i - pos[i])
            {
                return false;
            }
        }
        return true;
    }
    
    void Print()
    {
        vector<string> v;
        for (int i=0; i<pos.size(); i++)
        {
            string str(n, '.');
            str.replace(pos[i], 1, "Q");
            v.push_back(str);
        }
        result.push_back(v);
    }
    void backTrace(int row)
    {
        for (int i=0; i<n; i++)
        {
            if (isOk(row, i))
            {
                pos.push_back(i);
                if (row == n-1)
                {
                    Print();
                    pos.pop_back();
                    continue;
                }
                backTrace(row+1);
            }
        }
        pos.pop_back();
    }
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        backTrace(0);
        return result;
    }
    
    int n;
    vector<int> pos;
    vector<vector<string>> result;
};