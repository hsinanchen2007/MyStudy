```
class Solution {
    bool helper(vector<vector<char>>& b,int i, int j, string &w, int l){
        if(i>= b.size() || i<0 || j>=b[0].size() || j<0 || b[i][j]!=w[l]) return false;
        if(l==w.size()-1 && b[i][j]==w[l]) return true;
        char tmp = b[i][j];
        b[i][j] = '-'; //将当前字符修改为其他字符代表访问过
        bool res = helper(b,i+1,j,w,l+1)||helper(b,i-1,j,w,l+1)||helper(b,i,j+1,w,l+1)||helper(b,i,j-1,w,l+1); //向上下左右四个方向进行试探，递归
        b[i][j] = tmp; //还原当前字符
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                if(helper(board,i,j,word,0)) return true;
            }
        }
        return false;
    }
};
```
