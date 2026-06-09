### 解题思路
遍历每一个点统计周围的活细胞数，然后记录改点的细胞是否需要改变，然后再改变。

### 代码

```cpp
class Solution {
public:
    int fy[8] = {-1,1,0,0,-1,1,-1,1};
    int fx[8] = {0,0,-1,1,-1,-1,1,1};
    vector<pair<int,int>> change;
    void gameOfLife(vector<vector<int>>& board) {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                int countlive = 0;
                for(int k = 0; k < 8; k++)
                {
                    int y = i + fy[k];
                    int x = j + fx[k];
                    if(y >= 0 &&  y < board.size() && x >= 0 && x < board[i].size())
                    {
                        (board[y][x] == 1) && (countlive++);                      
                    }
                }
                if((board[i][j] == 1 && countlive < 2) || (board[i][j] == 1 && countlive > 3) || (board[i][j] == 0 && countlive == 3)) change.push_back(make_pair(i,j));
            }
        }

        for(auto x : change) board[x.first][x.second] = board[x.first][x.second] == 1 ? 0 : 1;

        return;
        
    }
};
```