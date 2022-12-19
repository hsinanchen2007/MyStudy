### 解题思路
需要注意的地方就是check里判断活细胞的个数，当board[x][y] == 3时也需要计算在内，因为它是由1转换而来
![image.png](https://pic.leetcode-cn.com/d599958915e462107b7bca309949d4e68fde3580714a6f10c64a584065e5f486-image.png)

### 代码

```cpp
int dx[8]={0,-1,-1,-1,0,1,1,1};
int dy[8]={1,1,0,-1,-1,-1,0,1};
class Solution {
public:

    bool check(int cur,vector<vector<int>>& board,int x,int y,int row,int col){
        int ans = 0;
        for(int i =0;i<8;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0&&nx<row&&ny>=0&&ny<col&&(board[nx][ny] == 1||board[nx][ny] == 3 )) ans++;
        }
        if(cur == 0&&ans == 3) return true;
        if(cur == 1 && ( ans < 2 || ans > 3)) return true;
        return false;
    }

    void gameOfLife(vector<vector<int>>& board) {
        //0如果改变状态->2  1 改变状态->3

        int row = board.size(),col = board[0].size();

        for(int i =0;i<row;i++){
            for(int j =0;j<col;j++){
                bool flag = check(board[i][j],board,i,j,row,col);
                if(flag) board[i][j] += 2;
            }
        }
        for(int i =0;i<row;i++) {
            for(int j =0;j<col;j++){
                if(board[i][j] == 2) board[i][j] = 1;
                if(board[i][j] == 3) board[i][j] = 0;
            }
        }

    }
};
```