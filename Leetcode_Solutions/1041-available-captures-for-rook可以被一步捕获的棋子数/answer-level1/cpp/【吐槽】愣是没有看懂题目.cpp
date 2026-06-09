### 解题思路
看了官方题解才真正了解了题目的意思，我觉得难点不是写代码，是看懂题目。

### 代码

```cpp
class Solution {
public:
    typedef pair<int, int> POS;
    int numRookCaptures(vector<vector<char>>& board) {
        int cnt = 0;
        POS start;
        vector<POS> dir = {make_pair(-1,0),make_pair(1,0),make_pair(0,-1),make_pair(0,1)};
        for(int i=0; i<8; ++i) {
            for(int j=0; j<8; ++j) {
                if(board[i][j] == 'R') {
                    start = make_pair(i,j);
                    break;
                }
            }
        }

        for(int i=0; i<4; ++i) {
            POS cur = start;
            while(cur.first>=0 && cur.first<8 && cur.second>=0 && cur.second<8) {
                if(board[cur.first][cur.second] == 'B') {
                    break;
                }
                if(board[cur.first][cur.second] == 'p') {
                    cnt += 1;
                    break;
                }
                cur.first += dir[i].first;
                cur.second += dir[i].second;                    
            }
        }
        return cnt;
    }
};
```