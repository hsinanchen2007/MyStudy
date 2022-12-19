### 解题思路
1. 模拟法+位运算, 有$O(1)$空间复杂度的解
2. 卷积求解

### 代码

```c++ []
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        R = board.size();
        C = board[0].size();
        // 模拟
        vector<int> pos;
        for(int i=0; i<R; ++i){
            for(int j=0; j<C; ++j){
                if(cellSim(i, j, board)){
                    pos.push_back(i*C+j);
                }
            }
        }
        
        // 下一次状态
        board = vector<vector<int>>(R, vector<int>(C, 0));
        for(int i=0; i<pos.size(); ++i){
            int p = pos[i];
            board[p/C][p%C]=1;
        }
    }

private:
    bool cellSim(int x, int y, vector<vector<int>>& board){
        int N = 0;
        for(auto d: dirs){
            int nx = x+d[0];
            int ny = y+d[1];
            if(inArea(nx, ny) && board[nx][ny]==1)
                N++;
        }

        if(board[x][y]==1){
            if(N < 2)
                return false;
            else if(N == 2 || N == 3)
                return true;
            else if(N > 3)
                return false;
        }
        else if(board[x][y]==0){
            if(N == 3)
                return true;
        }
        return false;
    }

    bool inArea(int x, int y){
        return 0<=x && x<R && 0<=y && y<C;
    }

private:
    vector<vector<int>> dirs = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    int R,C;
};
```
```java []
class Solution {
    public void gameOfLife(int[][] board) {
        // 位运算存储状态
        // 0x00: dead <-- dead
        // 0x01: dead <-- live
        // 0x10: live <-- dead
        // 0x11: live <-- live
        R = board.length;
        C = board[0].length;
        for(int i=0; i<R; ++i){
            for(int j=0; j<C; ++j){
                int N = cellsCnt(i, j, board);
                // update rules
                // 如果状态为0x00或者0x01, 在左移后默认为0
                if((board[i][j] & 0x01) == 1){
                    if(N ==2 || N==3)
                        board[i][j] = 0b11;
                }
                else{
                    if(N == 3)
                        board[i][j] = 0b10;
                }
            }
        }

        // RESET
        for(int i=0; i<R; ++i)
            for(int j=0; j<C; ++j)
                board[i][j] >>= 1;
        
    }

    // 计算pos (x, y)周围活细胞的数量
    private int cellsCnt(int x, int y, int[][] B){
        int N = 0;
        for(int []d: dirs){
            int nx = x+d[0];
            int ny = y+d[1];
            if(inArea(nx, ny)){
                N += (B[nx][ny] & 0x01);
            }
        }
        return N;
    }

    private boolean inArea(int x, int y){
        return 0<=x && x<R && 0<=y && y<C;
    }

    private int[][] dirs = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    private int R, C;
}
```
```python []
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # 参考熊猫大佬的卷积法
        from numpy import array, sum as np_sum
        R, C = len(board), len(board[0])
        # padding
        B = array([[0 for _ in range(C+2)] for _ in range(R+2)])
        B[1:R+1, 1:C+1] = array(board)
        
        # conv. kernel
        # 根据题意, 中间细胞状态取决于周围8个细胞, 01运算可以表达, 因此kernel选择如下
        conv_kernel = array([[1, 1, 1], [1, 0, 1], [1, 1, 1]])
        for i in range(1, R+1):
            for j in range(1, C+1):
                N = np_sum(B[i-1:i+2, j-1:j+2]*conv_kernel)
                if board[i-1][j-1] == 1:
                    if N < 2 or N >3:
                        board[i-1][j-1] = 0
                else:
                    if N == 3:
                        board[i-1][j-1] = 1
            
```