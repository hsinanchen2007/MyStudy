### 解题思路
刚开始写的算法运行超时，参考了题解，发现有两方面因素：
1.传参的时候传实参，节省占用内存
2.每一步的下一步采用或连接，节省运算量

### 代码

```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int c = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(helper(board,word,i,j,c)){
                        return true;
                    };
                }
            }
        }
        return false;
    }
    bool helper(vector<vector<char>>& board, string& word,int i,int j,int c){
        if(word[c]!=board[i][j]){
            return false;
        }
        c++;
        if(c==word.size()){
            return true;
        }
        char temp = board[i][j];
        board[i][j] = '0';
        if((i-1>=0&&helper(board,word,i-1,j,c))||(j-1>=0&&helper(board,word,i,j-1,c))||(i+1<board.size()&&helper(board,word,i+1,j,c))||(j+1<board[0].size()&&helper(board,word,i,j+1,c))){
            return true;
        }
        board[i][j] = temp;
        return false;
    }
};
```