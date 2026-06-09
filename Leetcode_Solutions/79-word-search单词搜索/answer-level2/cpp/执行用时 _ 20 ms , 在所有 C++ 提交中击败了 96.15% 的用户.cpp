### 解题思路
很简单，上下左右各走一遍，如果没有就回去
### 代码

```cpp
class Solution 
{
private:
    int rows;
    int cols;
    int pathLength = 0;
    bool * visited;
    int strsize = 0;
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        rows = board.size();
        cols = board[0].size(); 

        if(rows < 1 || cols < 1 )
        {
            return false;
        }
        strsize = word.size();
        visited = new bool[rows*cols];
        memset(visited,0, rows*cols);
        for(int row = 0; row < rows; ++row)
        {
            for(int col = 0; col < cols; ++col)
            {
                if(exist(board,row,col,word))
                    return true;
            }
        }
        delete [] visited;
        return false;
    }
    bool exist(vector<vector<char>>& board,int row,int col,string&word)
    {
        if(pathLength == strsize)
            return true;
        bool hasPath = false;
        if(row >= 0 && row < rows && col >= 0 && col < cols && 
        board[row][col] == word[pathLength] && !visited[row*cols+col])
        {
            ++pathLength;
            visited[row*cols+col] = true;
            hasPath = exist(board,row,col-1,word) || exist(board,row,col+1,word)
            || exist(board,row+1,col,word)||exist(board,row-1,col,word);
            if(!hasPath)
            {
                --pathLength;
                visited[row*cols+col] = false;
            }
        }
        return hasPath;
    }
};
```