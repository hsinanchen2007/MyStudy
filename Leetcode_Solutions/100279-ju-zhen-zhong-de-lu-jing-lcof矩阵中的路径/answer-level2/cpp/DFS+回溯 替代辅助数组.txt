### 解题思路
参考https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/solution/shen-sou-hui-su-by-hanwn/
用'.'代替已经匹配的字符，不需要再传入辅助数组。
### 代码

```cpp
class Solution {
public:
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int rows,cols;
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]==word[0]){
                    if(helpFunction(board,i,j,1,word)) return true;
                }
            }
        }
        return false;
    }
    bool helpFunction(vector<vector<char>>&board,int row,int col,int pos,string word){
        if(pos==word.size()) return true; // 到达末尾
        // 查看四个方向
        char temp = board[row][col];//暂时替代该值
        board[row][col] = '.';
        for(int i=0;i<=3;i++){
            int m = row + dir[i][0];
            int n = col + dir[i][1];
            if(m>=0&&m<rows&&n>=0&&n<cols&&board[m][n]==word[pos]){
                if(helpFunction(board,m,n,pos+1,word)) return true;
            }
        }
        board[row][col] = temp;
        return false;
    }
};