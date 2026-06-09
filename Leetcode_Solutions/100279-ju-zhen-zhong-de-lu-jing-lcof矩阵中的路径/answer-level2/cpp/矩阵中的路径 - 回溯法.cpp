### 解题思路
1. 在board中找到一个位置，使得`board[i][j] == word[0]`，可以作为搜索的入口
2. 由于一个格子不能重复进入，因此需要定义一个visit数组，保证每个格子只进入一次
3. 找到一个可行解即返回true。若该次搜索返回false，那么进行步骤`1.`，找到下一个可行的入口，进入下一次搜索
4. 直到遍历完整个board，仍没有搜索到目标路径，返回false

### 代码

```cpp
class Solution {
public:

    vector<vector<int>> dxy = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int rows, cols;
    bool dfs(vector<vector<char>>& board, vector<bool>& visit, int i, int j, string& word, int idx){
        if(board[i][j] != word[idx]) return false;
        visit[i*cols+j] = true;
        idx++;
        for(auto xy : dxy){
            int x = xy[0] + i;
            int y = xy[1] + j;
            if(x < 0 || x >= rows || y < 0 || y >= cols || visit[x*cols+y]) continue;
            else{
                if(dfs(board, visit, x, y, word, idx)) return true;
            }
        }
        visit[i*cols+j] = false;
        if(idx == word.size()) return  true;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(word == "")  return false;
        rows = board.size();
        cols = board[0].size();
        vector<bool> visit(rows * cols, false);
        for(int i = 0;i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, visit, i, j, word, 0)) return true;
                }
            }
        }
        return false;
    }
};
```