### 解题思路
常规思路，四个方向进行遍历，获得最终可吃掉的子的个数；

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int res = 0, x0 = 0, y0 = 0;
        int row = board.size(), col = board[0].size();
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'R'){
                    x0 = i, y0 = j;
                    break;
                }
            }
        }
        for(int k = 0; k < dir.size(); k++){
            int tmpx = x0+dir[k].first, tmpy = y0+dir[k].second;
            while(tmpx>=0 && tmpx<row && tmpy>=0 && tmpy < col){
                if(board[tmpx][tmpy] == 'B') break;
                if(board[tmpx][tmpy] == 'p'){
                    res++;
                    break;
                }
                tmpx += dir[k].first, tmpy += dir[k].second;
            }
        }
        return res;
    }
};
```