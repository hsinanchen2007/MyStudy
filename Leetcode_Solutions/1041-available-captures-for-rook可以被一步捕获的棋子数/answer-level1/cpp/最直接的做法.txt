### 解题思路
简单粗暴，先找'R'->O(n^2)，再东西南北找第一个不是'.'的字符。

### 代码

```cpp
class Solution {
public:

    void positionR(const vector<vector<char>>& board, int& Ri, int& Rj) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == 'R') {
                    Ri = i; 
                    Rj = j;
                }
            }
        }
    }

    int countP(const vector<vector<char>>& board, const int& Ri, const int& Rj) {
        int count = 0;

        int west  = Ri;
        int north = Rj;
        int east  = board.size() - 1 - Ri;
        int south = board.size() - 1 - Rj;

        while (west > 0) {
            auto here = board[west - 1][Rj];
            if (here != '.') {
                if (here == 'p') {
                    count++;
                }
                break;
            }
            west--;
        }

        while (north > 0) {
            auto here = board[Ri][north - 1];
            if (here != '.') {
                if (here == 'p') {
                    count++;
                }
                break;
            }
            north--;
        }

        while (east > 0) {
            auto here = board[board.size() - east][Rj];
            if (here != '.') {
                if (here == 'p') {
                    count++;
                }
                break;
            }
            east--;
        }

        while (south > 0) {
            auto here = board[Ri][board.size() - south];
            if (here != '.') {
                if (here == 'p') {
                    count++;
                }
                break;
            }
            south--;
        }

        return count;
    }

    int numRookCaptures(vector<vector<char>>& board) {
        int Ri = 0, Rj = 0;
        positionR(board, Ri, Rj);
        return countP(board, Ri, Rj);
    }
};
```