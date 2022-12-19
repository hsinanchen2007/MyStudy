有一个地方需要注意的是，当传入的参数较大时，尽量传引用而不是传值，否则递归过程中光是拷贝参数就要花费掉巨量的时间。
```
回溯法，记得是传引用而不是直接传值，否则光是两个矩阵的拷贝都要花费掉1000ms。

class Solution {
private:
//四个方向
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
public:
    bool dfs(vector<vector<bool>>&visited,vector<vector<char>>& board,int row,int col,int index,string &word){
        if(index==word.size()){
            return true;
        }
        //记录走过的点
        visited[row][col]=false; 
        for(int i=0;i<4;i++){
            row+=y[i];
            col+=x[i];
            //判断是否越界
            if(row>=0&&row<board.size()&&col>=0&&col<board[0].size()&&visited[row][col]){
                //若找到终点则直接返回，停止回溯。
                if(word[index]==board[row][col]&&dfs(visited,board,row,col,index+1,word)){
                    return true;
                }
            }
            //回溯
            row-=y[i];
            col-=x[i];
        }
        //回溯
        visited[row][col]=true;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),true));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]&&dfs(visited,board,i,j,1,word)){
                    return true;
                }
            }
        }
        return false;
    }
};
```
