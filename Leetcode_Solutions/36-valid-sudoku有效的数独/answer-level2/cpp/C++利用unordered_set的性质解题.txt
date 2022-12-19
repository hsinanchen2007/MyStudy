由于unodered_set的键值具有唯一性，可利用这种性质来进行求解。
遍历一次数组，然后将每行，每列，每个就宫格的不为空的数据插入到unordered_set中，同时统计插入的次数，如果次数和插入之后unordered_set的尺寸不一致，则表明相同的数据被unordered_set排除掉了，那么数独就不是有效的。
```
bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> h[9];
        unordered_set<int> v[9];
        unordered_set<int> s[3][3];
        int row[9];
        memset(row,0,sizeof(row));
        int sn[3][3];
        memset(sn,0,sizeof(sn));
        for(int i=0;i<9;i++)
        {
            int linenum=0;
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    linenum++;
                    row[j]++;
                    int m=i/3,n=j/3;
                    sn[m][n]++;
                    h[i].insert(board[i][j]);
                    v[j].insert(board[i][j]);
                    s[m][n].insert(board[i][j]);
                }
            }
            if(h[i].size()!=linenum)
                return false;
        }
        for(int i=0;i<9;i++)
        {
            if(row[i]!=v[i].size())
                return false;
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
                if(sn[i][j]!=s[i][j].size())
                    return  false;
        }
        return true;
    }
```
