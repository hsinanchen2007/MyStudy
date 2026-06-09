### 解题思路
利用DFS暴力搜索，沿着一条路径一直往下搜索，直到如果不满足搜索条件（某点超出矩阵范围或者搜索到的字符和word不相同）则返回到上一个节点进行这个节点的其余路径的判断。如果都不满足，则继续返回。这种题类似于遍历二叉树的前序遍历一样。先判断下一个节点是否满足题意，不满足，则返回false，满足则继续往下访问。

### 代码

```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    int rows = board.size();
    int cols = board[0].size();
    int i,j;
    for(i=0 ; i<rows ; i++)
    {
        for(j=0 ; j<cols ; j++)
        {
            if(board[i][j] == word[0])
                if(DFS(word , board , i , j , 0 , rows , cols))
                    return true;        
        }
    }
    return false;
    }
    bool DFS(string word , vector<vector<char>>&board , int i , int j , int k ,int rows , int cols)
    {
        if(i>=rows || i<0 || j>=cols || j<0 || board[i][j]!=word[k])
            return false;
        if(k==word.size()-1)
            return true;
        char temp = board[i][j];
        board[i][j] = '/';
        bool res = DFS(word , board , i+1 , j , k+1 , rows ,cols) || DFS(word , board , i-1 , j , k+1 , rows , cols) || DFS(word , board , i , j+1 , k+1 , rows , cols) || DFS(word , board , i , j-1 , k+1 , rows,cols);
        board[i][j] = temp;
        return res;

    }
};
```