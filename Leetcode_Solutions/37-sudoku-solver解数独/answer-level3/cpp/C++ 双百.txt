```
class Solution {
public:
    int x[10][10]={0},y[10][10]={0},z[10][10]={0};
    vector<int>E[10][10];
    vector<pair<int,int>>temp;
    int flag=0;
    void solve(vector<vector<char>>& board,int num) {
        if(num==temp.size()) {flag=1;return ;}
        int i=temp[num].first,j=temp[num].second;
        for(auto it :E[i][j]) {
            if(x[i][it]==0&&y[j][it]==0&&z[i/3*3+j/3][it]==0) {
                x[i][it]=y[j][it]=z[i/3*3+j/3][it]=1;
                board[i][j]='0'+it;
                solve(board,num+1);
                if(flag==1) return ;
                x[i][it]=y[j][it]=z[i/3*3+j/3][it]=0;
            }
        }
        return ;
    }
    void solveSudoku(vector<vector<char>>& board) {
        temp.clear();
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                E[i][j].clear();
                if(board[i][j]!='.') {
                    int t=board[i][j]-'0';
                    x[i][t]=y[j][t]=z[i/3*3+j/3][t]=1;
                }
                else temp.push_back({i,j});
            }
        }
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                for(int t=1;t<=9;t++) {
                    if(x[i][t]==0&&y[j][t]==0&&z[i/3*3+j/3][t]==0) E[i][j].push_back(t);
                }
            }
        }
        if(temp.size()!=0) solve(board,0);
    }
};
```
