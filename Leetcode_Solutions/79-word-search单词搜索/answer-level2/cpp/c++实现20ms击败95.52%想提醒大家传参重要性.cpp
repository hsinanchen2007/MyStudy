第一次dfs函数没有对word参数使用&word的方式传参，结果运行时间为138ms，消耗内存50mb，看了题解一位老哥的提醒使用了&word方式传参，结果瞬间提升为20ms，10mb内存。可见能使用 &name 传参的时候尽量要使用这种方式，有时候效率低未必是算法的问题。
```
class Solution {
public:
    int flag = 0;
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || board[0].size() == 0)
            return false;
        vector<vector<int>> v(board.size());
        for(int i = 0; i < v.size(); i++)
            v[i].resize(board[0].size());
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v[0].size(); j++){
                if(board[i][j] == word[0]){
                    dfs(board, v, i, j, 0, word);
                    if(flag)
                        return true;
                }
            }
        }
        return false;
    }
    void dfs(vector<vector<char>>& board, vector<vector<int>>& v, int i, int j, int cnt, string& word){
        if(flag)
            return;
        v[i][j] = 1;
        if(cnt == word.size()-1){
            flag = 1;
            return;
        }
        if(i-1 >= 0 && v[i-1][j] != 1 && board[i-1][j] == word[cnt+1])
            dfs(board, v, i-1, j, cnt+1, word);
        if(!flag && i+1 < v.size() && v[i+1][j] != 1 && board[i+1][j] == word[cnt+1])
            dfs(board, v, i+1, j, cnt+1, word);
        if(!flag && j-1 >= 0 && v[i][j-1] != 1 && board[i][j-1] == word[cnt+1])
            dfs(board, v, i, j-1, cnt+1, word);
        if(!flag && j+1 < v[0].size() && v[i][j+1] != 1 && board[i][j+1] == word[cnt+1])
            dfs(board, v, i, j+1, cnt+1, word);
        v[i][j] = 0;
    }
};
```
