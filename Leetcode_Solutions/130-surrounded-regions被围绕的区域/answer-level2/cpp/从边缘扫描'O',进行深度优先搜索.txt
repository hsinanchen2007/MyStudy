### 解题思路
1. 定义一个mask二维数组，将其所有元素初始化为1
2. 从board的边缘开始扫描看是否有'O'，假如发现'O'，从该'O'开始进行bfs，将与该'O'相邻的位置的mask值都改为0
3. 最后遍历整个board，找到该位置的mask值为1的'O'，将其改为'X'

### 代码

```cpp
class Solution {
public:
    int row, col;
    vector<vector<int>> mask;
    vector<vector<int>> dxy = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    void dfs(vector<vector<char>>& board, int i, int j){
        mask[i][j] = 0;
        for(auto ele: dxy){
            int x = i+ele[0];
            int y = j+ele[1];
            if(x<0 || x>=row || y<0 || y>=col || mask[x][y] == 0 || board[x][y] == 'X') continue;
            dfs(board, x, y);
        }
    }

    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        row = board.size();
        col = board[0].size();
        mask = vector<vector<int>>(row, vector<int>(col, 1));
        // 第0行
        for(int i=0, j=0;j<col;j++){
            if(board[i][j]=='O')
                dfs(board, i, j);
        }
        // 最后一行
        for(int i=row-1, j=0;j<col;j++){
            if(board[i][j] =='O')
                dfs(board, i, j);
        }
        // 第0列
        for(int j=0, i=0;i<row;i++){
            if(board[i][j] =='O')
                dfs(board, i, j);
        }
        // 最后一列
        for(int j=col-1, i=0;i<row;i++){
            if(board[i][j] =='O')
                dfs(board, i, j);
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]== 'O' && mask[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};
```