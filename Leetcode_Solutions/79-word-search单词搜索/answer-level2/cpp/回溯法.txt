### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
    int dir[4][2] = {{0, 1},{1, 0}, {0 ,-1}, {-1, 0}};
    int m,n;
    vector<vector<bool>> vis;
    bool isInArea(int x, int y) {
        if(x<0||y<0||x>=m||y>=n) {
            return false;
        }
        return true;
    }
    bool dfs(vector<vector<char>>& board, string word, int index, int startx, int starty) {
        // 截止条件
        if(index == word.size() - 1) {
            return board[startx][starty] == word[index];
        }
        //遍历候选节点
        if(board[startx][starty] == word[index]) {
            vis[startx][starty] = true;
            for(int i = 0; i <= 3; i++) {
                int newx = startx + dir[i][0];
                int newy = starty + dir[i][1];
                if(isInArea(newx, newy) && !vis[newx][newy]) {
                    if(dfs(board, word, index+1, newx, newy)) {
                        return true;
                    }
                }
            }
            vis[startx][starty] = false;
        }
        
        return false;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        vis = vector<vector<bool>> (m,vector<bool>(n, false));
        for(int i = 0;i<m;i++){
            for(int j = 0; j<n;j++){
                if(dfs(board,word,0,i,j)) {
                    return true;
                }
            }
        }
        return false;
    }
};
```