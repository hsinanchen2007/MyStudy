### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/11b29c0b01da4fab2f4d73e2678637c384cf45582310e166265e6ba6bf637852-image.png)

### 代码

```cpp
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,int i,int j,int k)
    {
        if(k==word.size())return true;
        if(i<0||i>=board.size()||j<0||j>=board[0].size()) return false;
        if(board[i][j]=='0'||board[i][j]!=word[k]) return false;

        char tp=board[i][j];board[i][j]='0';
        if(dfs(board,word,i+1,j,k+1))  return true;
        if(dfs(board,word,i-1,j,k+1))  return true;
        if(dfs(board,word,i,j+1,k+1))  return true;
        if(dfs(board,word,i,j-1,k+1))  return true;
        board[i][j]=tp;
        return  false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(dfs(board,word,i,j,0)) return true;
        return false;
    }
};
```