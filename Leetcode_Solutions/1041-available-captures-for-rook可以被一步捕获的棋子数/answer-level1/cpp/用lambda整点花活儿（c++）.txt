加个lambda表达式，可以通过很简单的扩展来覆盖其他棋子的走法
题目很简单，直接上代码
```
class Solution {
public:
    vector<vector<char>>* board;
    int checknext(pair<int, int> point, function<void(pair<int, int>&)> move) {
        while (point.first >= 0 && point.first < 8 && point.second >= 0 && point.second < 8) {
            if ((*board)[point.first][point.second] == 'B') {
                return 0;
            }
            if ((*board)[point.first][point.second] == 'p') {
                return 1;
            }
            move(point);
        }
        return 0;
    }
    int numRookCaptures(vector<vector<char>>& board) {
        this->board = &board;
        int count = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] != 'R') {
                    continue;
                }
                count += checknext(pair<int, int>(i, j), [](pair<int, int>& p) {p.second++; });
                count += checknext(pair<int, int>(i, j), [](pair<int, int>& p) {p.second--; });
                count += checknext(pair<int, int>(i, j), [](pair<int, int>& p) {p.first++; });
                count += checknext(pair<int, int>(i, j), [](pair<int, int>& p) {p.first--; });
                return count;
            }
        }
        return count;
    }
};
```
