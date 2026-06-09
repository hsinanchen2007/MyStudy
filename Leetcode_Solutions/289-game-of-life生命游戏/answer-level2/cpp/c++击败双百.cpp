### 解题思路
这题比较简单，遍历八个方向的活细胞，统计即可。

### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size() == 0) return;
        vector<vector<int>> result = board;
        vector<vector<int>> direct = {{0,1},{1,0},{0,-1},{-1,0},{1,-1},{-1,1},{-1,-1},{1,1}};

        int xlimit = board.size();
        int ylimit = board[0].size();
        for(int x = 0; x < xlimit;++x){
            for(int y = 0; y < ylimit;++y){
                int sum = 0;
                for(int i = 0; i < 8;++i){
                    int newx = x+direct[i][0];
                    int newy = y+direct[i][1];
                    if(newx>=0&&newx<xlimit&&newy>=0&&newy<ylimit){
                        if(board[newx][newy])
                            sum++;
                    }
                }

                if(board[x][y]){
                    if(sum<2 || sum>3){
                        result[x][y]=0;
                    }
                }else{
                    if(sum == 3){
                        result[x][y]=1;
                    }
                }
            }
        }
        board = result;
    }
};
```