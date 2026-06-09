### 解题思路
关键就是处理边界
如果内部的‘O’能和边界联通的话，那这部分的‘O’就不能改变
如果内部的‘O’的区域不能和边界‘O’联通的话，那这部分的‘O’就要变成‘X’

所以先处理边界的‘O’与内部‘O’联通的情况，将这部分‘O’用‘#’来代替；
最后再将‘#’换回‘X’，因为这部分‘O’与边界联通
然后再将最后剩下的‘O’，即为图中内部的‘O’换为‘X’。

### 代码

```cpp
class Solution {
public:
    int dir[4][2]={-1,0,1,0,0,-1,0,1};//四个方向
    void solve(vector<vector<char>>& board) {
        if(board.size()<1){
            return ;//如果只有一行或为空就直接返回
        }
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool edge=(i==0||j==0||i==n-1||j==m-1);
                if(edge&&board[i][j]=='O'){
                    bfs(board,i,j);//入口
                }
            }
        }
        for(int i=0;i<n;i++){//最后替换
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
    }
    void bfs(vector<vector<char>> &board,int x,int y){
        queue<pair<int,int>> q;
        q.push(make_pair(x,y));
        board[x][y]='#';//将边界入口‘O’变成‘#’
        while(!q.empty()){//再进行广度优先搜索
            pair<int,int> t=q.front();
            q.pop();
            for(int i=0;i<4;i++){//从四个方向开始找
                int nx=t.first+dir[i][0];//附近点的x的坐标
                int ny=t.second+dir[i][1];//附近点的y的坐标
                if(nx>=0&&nx<board.size()&&ny>=0&&ny<board[0].size()&&board[nx][ny]=='O'){//如果这个点也为‘O’就将他变成‘#’，并放进队列，寻找他附近的‘O’
                    board[nx][ny]='#';
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
};
```