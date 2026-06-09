### 解题思路
暴力解法

### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> old = board;
        vector<pair<int, int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
        int row = board.size(), col = board[0].size(), count = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                count = 0;
                for(auto di:dir){
                    int x = i+di.first, y = j+di.second;
                    if(x>=0 && x<row && y>=0 && y<col && old[x][y]) count++;
                }
                if(old[i][j] && count<2) board[i][j] = 0;
                if(old[i][j] && (count==2 || count==3)) board[i][j] = 1;
                if(old[i][j] && count>3) board[i][j] = 0;
                if(!old[i][j] && count==3) board[i][j] = 1;
            }
        }
    }
};
```