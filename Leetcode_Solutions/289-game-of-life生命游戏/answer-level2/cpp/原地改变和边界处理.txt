### 解题思路
边界处理用了一个自己整理的模板但时执行效率还可以缩减
原地处理只要把改变的细用不同的数字表示再用一次循环处理就可以了

### 代码

```cpp
class Solution {
private:
    struct pos{
        int x;
        int y;
    };
    int dx[8] = {-1,-1,-1,0,0,1,1,1};int dy[8] = {-1,0,1,-1,1,-1,0,1}; // 外边框
    unordered_map<int, vector<bool>>confinex = {
        {0,{false,false,false,true,true,true,true,true}}, // 上边界
    }; // 
    unordered_map<int, vector<bool>>confiney = {
        {0,{false,true,true,false,true,false,true,true}}, // 左边界
    }; // 
public:
    void gameOfLife(vector<vector<int>>& board) {
        // 探测周围细胞
        // 0 -> 1 -1
        // 1 -> 0 +1
        // 再次循环
        if(board.size() > 0){
            if(board.size()>1) confinex[board.size()-1] = {true,true,true,true,true,false,false,false};
            else confinex[0] = {false,false,false,true,true,false,false,false};
            if(board[0].size()>1) confiney[board[0].size()-1] = {true,true,false,true,false,true,true,false};// 边界信息
            else confiney[0] = {false,true,false,false,false,false,true,false};
            for(int i=0; i<board.size(); ++i){
                for(int j=0; j<board[0].size(); ++j){
                    border(board, {i, j});
                }
            }
            for(int i=0; i<board.size(); ++i){
                for(int j=0; j<board[0].size(); ++j){
                    if(board[i][j] > 1) board[i][j] = 0; // 1 -> 0
                    else if(board[i][j] < 0) board[i][j] = 1; // 0 -> 1
                }
            }
        } // 预防空
    }
    void border(vector<vector<int>>& grid, pos cur){
        int n = 0;
        if(confinex.count(cur.x)||confiney.count(cur.y)){
            vector<bool> tag(8,true);
            for(int i=0; i<8; ++i){
                if(confinex.count(cur.x)) tag[i] = (tag[i] && confinex[cur.x][i]);
                if(confiney.count(cur.y)) tag[i] = (tag[i] && confiney[cur.y][i]);
                if(tag[i] && grid[cur.x+dx[i]][cur.y+dy[i]]>0) ++n;
            } 
        }// 边界点
        else{
            for(int i=0; i<8; ++i){
                int x = cur.x + dx[i], y = cur.y + dy[i];
                if(grid[x][y] > 0) ++n;// 1 本身为活细胞， 2 为上一轮由活细胞变为死细胞
            }
        }
        if(n == 3 && !grid[cur.x][cur.y]) --grid[cur.x][cur.y];// 自左向右，自上向下扫描，每个待改变位置的细胞未被改变
        if(( n < 2 || n > 3)&& grid[cur.x][cur.y]) ++grid[cur.x][cur.y]; // 该活细胞死亡 
    }
};
```