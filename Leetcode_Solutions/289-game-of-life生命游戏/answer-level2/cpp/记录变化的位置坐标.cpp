### 解题思路
按题目意思遍历数组，如果状态发生变化，则记录发生变化的位置，遍历结束后，再更新原数组

### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int,int>> record;
        vector<int> dir_x={-1,0,1,-1,1,-1,0,1};
        vector<int> dir_y={-1,-1,-1,0,0,1,1,1};
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==0){
                    int cnt=0;
                    for(int k=0;k<8;k++){
                        if(i+dir_x[k]>=0&&i+dir_x[k]<board.size()&&j+dir_y[k]>=0
                        &&j+dir_y[k]<board[0].size()&&board[i+dir_x[k]][j+dir_y[k]]==1) cnt++;
                    }
                    if(cnt==3) record.push_back(make_pair(i,j));
                }
                else{
                    int cnt=0;
                    for(int k=0;k<8;k++){
                        if(i+dir_x[k]>=0&&i+dir_x[k]<board.size()&&j+dir_y[k]>=0
                        &&j+dir_y[k]<board[0].size()&&board[i+dir_x[k]][j+dir_y[k]]==1) cnt++;
                    }
                    if(cnt<2||cnt>3) record.push_back(make_pair(i,j));                 
                }
            }
        }
        for(int i=0;i<record.size();i++){
            int x=record[i].first,y=record[i].second;
            board[x][y]=abs(board[x][y]-1);
        }
    }
};
```