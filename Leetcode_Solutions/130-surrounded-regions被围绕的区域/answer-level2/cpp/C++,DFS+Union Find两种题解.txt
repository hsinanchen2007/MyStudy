解法一：
DFS:
```
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
class Solution {
public:
//DFS，首先求出边界为O的，从边界为O的连通图全部设置成y，表明这个连通的没有被包围，之后遍历整个图，出现为0的复制成x
    void dfs(vector<vector<char>>& board,int i,int j){
        board[i][j]='Y';
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0&&y>=0&&x<board.size()&&y<board[0].size()&&board[x][y]=='O'){
                dfs(board,x,y);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(i==0||j==0||i==board.size()-1||j==board[0].size()-1){
                    if(board[i][j]=='O'){
                        dfs(board,i,j);
                        //cout<<board[i][j]<<" ";
                    }
                    
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O')board[i][j]='X';
                else if(board[i][j]=='Y')board[i][j]='O';
            }
        }
    }
};
```
解法二：
Union Find(并查集)：
```
const int maxn=0x7fffff;
//typedef long long ll;
int father[maxn];

class Solution {
public:
//Union Find解法
    int find(int x){
        int j=x;
        while(father[x]!=x){
            x=father[x];
        }
        while(father[j]!=x){//这个路径压缩，需要写，否则过不去，会出现超时的情况
            father[j]=x;
        }
        return x;
    }
    void uni(int i,int j){
        int f1=find(i);
        int f2=find(j);
        father[f1]=f2;
    }
    void solve(vector<vector<char>>& board) {
        if(board.size()==0||board[0].size()==0)return ;
       // int m=board.size(),n=board[0].size();
        int temp=board.size()*board[0].size();
        for(int i=0;i<=temp;i++){
            father[i]=i;
        }
        //int temp=m*n;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='X')continue;
                int k=i*board[0].size()+j;
                if(i==0||j==0||i==board.size()-1||j==board[0].size()-1){
                    uni(k,temp);//这个是不需要删去的。。。
                    continue;
                }
                else if(board[i][j]=='O'){
                        if(board[i][j-1]=='O')uni(k,k-1);
                        if(board[i][j+1]=='O')uni(k,k+1);
                        if(board[i-1][j]=='O')uni(k,k-board[0].size());
                        if(board[i+1][j]=='O')uni(k,k+board[0].size());
                }
            }
        }
        int temp_father=find(temp);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int k=i*board[0].size()+j;
                if(board[i][j]=='X')continue;
                //if(father[k]!=k&&board[i][j]=='O')board[i][j]='X';//这样会出现错误，因为第一个的父亲一定是自己
                //if(father[k]!=temp&&board[i][j]=='O')board[i][j]='X';
                if(find(k)!=temp_father)board[i][j]='X';
            }
        }
    }
};
```
