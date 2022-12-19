
注意点：
    1.如何对越界条件进行判断
    2.怎样对当前所在字符进行标记处理
```
class Solution {
private:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k)
    {
        if( i<0 || i>=board.size() ||   //  左右是否越界
            j<0 || j>=board[0].size() || // 上下是否越界
            board[i][j] != word[k] )    //  字符是否匹配
            return false;
        if( k == word.length()-1 )  // 字符串匹配次数相等，符合题意，开始向上回溯
            return true;
        char tmp = '#';         //将当前所在位置元素标记为已经走过，防止重复
        swap(tmp, board[i][j]);
        bool res = dfs(board, word, i+1, j, k+1) ||
                  dfs(board, word, i-1, j, k+1) ||
                  dfs(board, word, i, j+1, k+1) ||
                  dfs(board, word, i, j-1, k+1);
        if (res == false) //res 为 False 时：说明此路不通，将 board[i][j] 进行还原
            board[i][j] = tmp;
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                if(dfs(board,word,i,j,0))
                    return true;
        return false;
        
    }
};
```
