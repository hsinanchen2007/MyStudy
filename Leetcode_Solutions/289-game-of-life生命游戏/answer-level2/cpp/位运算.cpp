### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        if(n==0||m==0)return;
        int dx[8]={1,-1,0,0,1,-1,-1,1};
        int dy[8]={0,0,1,-1,1,-1,1,-1};
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
            {
                int cnt=0;
                for(int k = 0; k < 8; ++k)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x<0 || x>=n || y <0 || y>=m)continue;
                    cnt += board[x][y]&1;
                }
                if(board[i][j]&1>0)
                {
                    if(cnt>=2&&cnt<=3)
                        board[i][j] = 0b11;
                }
                else if(cnt==3)
                    board[i][j] = 0b10;
            }
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                board[i][j] >>=1;
    }
};
```