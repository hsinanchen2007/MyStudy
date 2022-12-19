### 解题思路
刚开始自己没有考虑到数组中字母重复使用的问题，看了别人的题解解决了
### 代码

```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) { 
        int m=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[m]){
                    if(xunhuan(board,word,i,j,m+1)) return true;
                }
            }
        }
        return false;    
    }
    bool xunhuan(vector<vector<char>>& board, string word,int i,int j,int m){
        char tmp = board[i][j];
        board[i][j] = 0; 
        if(m==word.size()) return true;
        else{
            if(i-1>=0 && board[i-1][j]==word[m]){
                if(xunhuan(board,word,i-1,j,m+1)) 
                    return true;
            }
            if(i+1<board.size() && board[i+1][j]==word[m]){
                if(xunhuan(board,word,i+1,j,m+1))
                     return true;
            } 
            if(j-1>=0 && board[i][j-1]==word[m]){
                if(xunhuan(board,word,i,j-1,m+1))
                     return true;
            }
            if(j+1<board[0].size() && board[i][j+1]==word[m]){
                if(xunhuan(board,word,i,j+1,m+1))
                     return true;
            } 
        }
        board[i][j]=tmp;
        return false;
    }
};
```