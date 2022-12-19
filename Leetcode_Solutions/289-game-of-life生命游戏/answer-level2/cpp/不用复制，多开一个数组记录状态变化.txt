### 解题思路
题目乍一看，没有返回值，就只能在原数据上更改了，于是想到用一个数组记录这个位置是否发生过变化，这样在更新之后也能知道更新前的状态。
![image.png](https://pic.leetcode-cn.com/0b9fab333c3c3dfc656a2662275b27e4e9bbe98d683cf2ac694de25889d69773-image.png)


### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        int dx[] = {-1,0,1,1,1,0,-1,-1};
        int dy[] = {-1,-1,-1,0,1,1,1,0};
        vector<vector<bool>> flip(m, vector<bool>(n, false)); // 用一个辅助数组来判断是否状态有变化
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int cnt = 0;
                for(int k=0; k<8; k++) {
                    int tx = i+dx[k];
                    int ty = j+dy[k];
                    if(tx >= 0 && tx < m && ty >= 0 && ty < n) {
                        cnt += flip[tx][ty] ^ board[tx][ty]; // 0^1=1,1^1=0 即原状态
                    }
                }
                if(board[i][j] == 1) {
                    if(cnt > 3 || cnt < 2) {
                        board[i][j] = 0;
                        flip[i][j] = 1;
                    }
                } else {
                    flip[i][j] = board[i][j] = cnt == 3;
                }
            }
            
        }
    }
};
```