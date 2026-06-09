```
class Solution {
public:
//DFS处理，同一个单元格的字母不能被重复使用，所以需要进行去重处理，
//常见的去重方法就是vis[i]
//一条路走到底，没有先后顺序，通常采用的是DFS
    bool dfs(vector<vector<char>>& board,string word,int pos,int i,int j,int m,int n,vector<vector<int>>&vis){
        if(pos==word.length()){
            return true;
        }
        //下面写的是主循环，四个方向进行遍历一下。。。
        if(i>0&&!vis[i-1][j]&&board[i-1][j]==word[pos]){//当前没有访问过，同时当前位置也是我们需要找的位置的字符，那么OK，DFS递归
            vis[i-1][j]=1;
            if(dfs(board,word,pos+1,i-1,j,m,n,vis))return true;
            vis[i-1][j]=0;
        }
        if(i<m-1&&!vis[i+1][j]&&board[i+1][j]==word[pos]){
            vis[i+1][j]=1;
            if(dfs(board,word,pos+1,i+1,j,m,n,vis))return true;
            vis[i+1][j]=0;
        }
        if(j>0&&!vis[i][j-1]&&board[i][j-1]==word[pos]){
            vis[i][j-1]=1;
            if(dfs(board,word,pos+1,i,j-1,m,n,vis))return true;
            vis[i][j-1]=0;//回溯，返回初始状态方便下一次访问处理
        }
        if(j<n-1&&!vis[i][j+1]&&board[i][j+1]==word[pos]){
            vis[i][j+1]=1;
            if(dfs(board,word,pos+1,i,j+1,m,n,vis))return true;
            vis[i][j+1]=0;//回溯法
        }
        return false;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        if(m==0||n==0)return false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    vector<vector<int>>vis(m,vector<int>(n,0));//vis一定要设置在这个位置，就是每一次均初始化一下。。。
                    //注意第一个找到的位置一定要先设置成1
                    vis[i][j]=1;
                    if(dfs(board,word,1,i,j,m,n,vis)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
```
