```cpp
class TicTacToe {
public:
    TicTacToe(int n) : rows(n, vector<int>(2, n)), cols(n, vector<int>(2, n)), l45(2, n), l135(2, n) {
        ln = n;
    }

    int move(int row, int col, int player) {
        int ind = player - 1;
        rows[row][ind]--;
        cols[col][ind]--;
        l45[ind] -= (col == row) ? 1 : 0;
        l135[ind] -= (col + row == ln - 1) ? 1 : 0;
        return (!rows[row][ind] || !cols[col][ind] || !l45[ind] || !l135[ind]) ? player : 0;
    }
    
    int ln;
    vector<vector<int>> rows;
    vector<vector<int>> cols;
    vector<int> l45;
    vector<int> l135;
};

auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
```