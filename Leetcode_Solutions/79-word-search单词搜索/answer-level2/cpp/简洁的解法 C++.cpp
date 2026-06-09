**代码很简洁，无需赘述**
```
class Solution {
private:
    bool exist(vector<vector<char>>& board,int y,int x, string& word,int i){
        if(i == word.size()) return true;// i代表已匹配成功的长度
        if(x<0||y<0||y==board.size()||x==board[y].size()) return false;//此为边界条件
        if(word[i]!=board[y][x]) return false;//在该处的单词不能成功匹配时返回false
        board[y][x]='*';//标记此处被访问了
        bool result=exist(board,y-1,x,word,i+1)//这四行代表从四个方向寻找
                ||exist(board,y,x-1,word,i+1)
                ||exist(board,y+1,x,word,i+1)
                ||exist(board,y,x+1,word,i+1);
        board[y][x]=word[i];//把标记改回原来的字母
        return result;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(exist(board,i,j,word,0)) return true;
            }
        }
        return false;
    }
};
```
