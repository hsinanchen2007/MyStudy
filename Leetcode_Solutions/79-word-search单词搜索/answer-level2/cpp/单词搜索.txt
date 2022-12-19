### 解题思路


### 代码

```cpp
class Solution {
public:
    int m,n;
    //定义四个方向，便于计算坐标变换
    int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
    bool exist(vector<vector<char>>& board, string word) {
        if(!board.size() || !board[0].size()) return false;
        m = board.size(),n = board[0].size();
        //枚举起点
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                if(dfs(board,i,j,0,word)) return true;
        return false;
    }
    bool dfs(vector<vector<char>>& board,int x,int y,int u,string& word){
        if(board[x][y] != word[u]) return false;    
        if(u == word.size() - 1) return true;   //匹配成功，则返回
        board[x][y] = '*';  //这里可以用其他字符代替，只要别与网格中字符相同即可
        //枚举四个方向
        for(int i = 0;i < 4;i++){
            int tx = x + dx[i],ty = y + dy[i];  
            //继续深搜的条件
            if(tx >= 0 && tx < m && ty >= 0 && ty < n && board[tx][ty] != '*'){
                if(dfs(board,tx,ty,u+1,word))
                    return true;
            }
        }
        board[x][y] = word[u];  //恢复现场
        return false;
    }
};
```