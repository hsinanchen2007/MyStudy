这个题可以扩展一下，在 m x n的棋盘上，先连出 thresh 个相同棋子的人获胜，其他条件不变。
思路就是遍历整个棋盘，每一步朝右上，右， 右下，下四个方向 搜索看最多有多少同样棋子。如果发现满足胜利条件，记录下胜利一方。
如果已经发现一方胜利了，则再遇到他的棋子都可以跳过不管。
如果遍历过程中发现双方都胜利了，显然不合理，直接返回 false。
如果遍历结束，说明没出现双赢的不合理情况。但是注意，可能有一方胜利，这时候要统计棋子的数量，看是否合理。
如果先手胜，那么先手棋子一定比后手多一个；
如果后手胜，那么棋子数一定想等；
如果没人取胜，那么先手可能比后手多一个，也可能想等。
除此之外，都是不合理的。
```c++
class Solution {
public:
    vector<vector<int>> four = {{-1, 1}, {1, 0}, {1, 1}, {0, 1}};
    bool validTicTacToe(vector<string>& board) {
        int c1 = 0;
        int c2 = 0;
        bool win1 = false;
        bool win2 = false;
        int win_thresh = 3;
        for(int i=0;i<board.size();++i) {
            for(int j=0;j<board[0].size();++j) {
                if(board[i][j] == ' ') continue;
                board[i][j] == 'X' ? c1++ : c2++;
                if((board[i][j] == 'X' && win1) || (board[i][j] == 'O' && win2)) continue;
                for(auto d: four) {
                    int l = 0;
                    //如果上个位置是同样棋子，并且没取胜，那么从这个棋子往下必然不能取胜，所以也不需要再往下搜索了
                    if(li >= 0 && li < board.size() && lj >= 0 && lj < board[0].size() && board[li][lj] == board[i][j]) continue;

                    dfs(board, d, win_thresh, i, j, l);
                    
                    if(l >= win_thresh) {
                        board[i][j] == 'X' ? win1 = true : win2 = true;
                        break;
                    }
                }
                if(win1 && win2) return false;
            
            }
        }

        if(win1) {
            return c1 == c2 + 1;
        } else if(win2) {
            return c1 == c2;
        } else {
            return c1 == c2 + 1 || c1 == c2;
        }

        
    }
    void dfs(vector<string>& board, vector<int> direction, int thresh, int i, int j, int& length) {
            length++;
            if(length >= thresh) return;
            int ni = i + direction[0];
            int nj = j + direction[1];
            char c = board[i][j];
            if(ni >= 0 && ni < board.size() && nj < board[0].size() && board[ni][nj] == c) 
                dfs(board, direction, thresh, ni, nj, length);
            else
                return;
    }
    
};
```