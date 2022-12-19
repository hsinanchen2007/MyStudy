``` C++ []
class TicTacToe {
public:
    vector<vector<int> > cols;
    vector<vector<int> > rows;
    vector<int> diag1;
    vector<int> diag2;
    int n;
    vector<int> indices{0, 1};
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        cols = vector<vector<int> >(n, {0, 0});
        rows = vector<vector<int> >(n, {0, 0});
        diag1 = vector<int>(n, 0);
        diag2 = vector<int>(n, 0);
        this->n = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int k = indices[player - 1];
        ++cols[col][k];
        ++rows[row][k];
        if (row + col == n - 1) ++diag1[k];
        if (row == col) ++diag2[k];
        if (cols[col][k] == n || rows[row][k] == n || diag1[k] == n || diag2[k] == n) {
            return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
```

![image.png](https://pic.leetcode-cn.com/cb1cf6ae22b99c01b650b0592eff8fb06c3ed1a42d38fd9b9b1d5d48a3ee22ac-image.png)
