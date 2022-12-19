### 解题思路
此处撰写解题思路
苦力活
### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty()) return;
        vector<vector<int>> backup;
        for(int i=0; i<board.size(); ++i){
            vector<int> a(board[i]);
            backup.push_back(a);
        }
        int row = backup.size();
        int col = backup[0].size();
        for(int i=0; i<backup.size(); ++i){
            for(int j=0; j<backup[0].size(); ++j){
                int living = 0;
                for(int m=-1; m<=1; ++m){
                    for(int k=-1; k<=1; ++k){
                        if(m==0 && k==0) continue;
                        int nx = i+m;
                        int ny = j+k;
                        if(nx<0 || nx>=row || ny<0 || ny>=col) continue;
                        if(backup[nx][ny] == 1) living++;
                    }
                }
                if(living<2) board[i][j] = 0;
                else if((living==2 || living==3) && board[i][j]==1) board[i][j] = 1;
                else if(living > 3) board[i][j] = 0;
                else if(living == 3) board[i][j] = 1;
            }
        }
    }
};
```