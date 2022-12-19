### 解题思路
**回溯法三步骤**
- `choose`
- `explore`
- `unchoose`

**choose**的意思是假如当前的路线可选，那么就选择当前的路线。假如当前的选择只能选一次，则需要增加标记数组，标记当前的选择被选过。如有路A-B-C，假如每条路只能走一次，那么不会出现A-B-A这样的走法（走了回头路）。
**explore**往往通过递归实现。是在当前的基础上，看还有没有选择可以完成目的。
**unchoose**是在**choose**的基础上，**explore**没有其他选择可以完成目的，那么说明当初就不该**choose**这条无法到达目的的路线，而是应该**choose**其他路线。



### 代码

```cpp
class Solution {
public:

    bool helper(const vector< vector<char> >& board, string word, vector < vector<int> >& visited){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0]){
                    visited[i][j] = true;
                    if(dfs(board, visited, word, i, j, 1)) return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
    bool dfs(const vector< vector<char> >& board, vector < vector<int> >& visited, string word, int row, int col, int index){
        if(index == word.length()){
            cout << "index:" << index << ";" << "length:" << word.length() <<endl;
            return true;
        } 
        if(row+1 < board.size() && !visited[row+1][col] && board[row+1][col] == word[index]){
            visited[row+1][col] = true;
            //输出路径
            // cout << "(" << row+1 << "," << col << ")" <<endl; 
            if(dfs(board, visited,  word, row+1, col, index+1)) return true;
            visited[row+1][col] = false;
        }
        if(row-1 >= 0 && !visited[row-1][col] && board[row-1][col] == word[index]){
            visited[row-1][col] = true;
            //输出路径
            // cout << "(" << row-1 << "," << col << ")" <<endl;
            if(dfs(board, visited, word, row-1, col, index+1)) return true;
            visited[row-1][col] = false;
        }
        if(col-1 >= 0 && !visited[row][col-1] && board[row][col-1] == word[index]){
            visited[row][col-1] = true;
            //输出路径
            // cout << "(" << row << "," << col-1 << ")" <<endl;
            if(dfs(board, visited, word, row, col-1, index+1)) return true;
            visited[row][col-1] = false;
        }
        if(col+1 < board[0].size() && !visited[row][col+1] && board[row][col+1] == word[index]){
            visited[row][col+1] = true;
            //输出路径
            // cout << "(" << row << "," << col+1 << ")" <<endl;
            if(dfs(board, visited, word, row, col+1, index+1)) return true;
            visited[row][col+1] = false;
        }
        return false;
    }

    bool exist(vector< vector<char> >& board, string word) {
        int row = board.size();
        int col = board[0].size();
        vector < vector<int> > visited(row, vector<int>(col,0));
        if(helper(board, word, visited)) return true;
        return false;     
    }
};

```