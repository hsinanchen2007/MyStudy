```
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int spicified_value = 1;
        map<int,int> rows[9];//列
        map<int,int> columns[9];
        map<int,int> boxs[9];
        for(int i = 0;i < 9;i ++)
            for(int j = 0;j < 9;j ++){
                int n = board[i][j];
                if(n == '.') continue;

                if(rows[i].find(n) != rows[i].end()
                    || columns[j].find(n) != columns[j].end()
                    || boxs[i/3 + j / 3 * 3].find(n) != boxs[i/3 + j / 3 * 3].end()){
                    return false;
                }
                rows[i].insert(make_pair(n,spicified_value));
                columns[j].insert(make_pair(n,spicified_value));
                boxs[i/3 + j / 3 * 3].insert(make_pair(n,spicified_value));
            }
        return true;
    }
};
```
