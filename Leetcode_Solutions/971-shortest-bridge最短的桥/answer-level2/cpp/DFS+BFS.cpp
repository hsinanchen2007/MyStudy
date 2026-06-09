### 解题思路
![image.png](https://pic.leetcode-cn.com/b684be1ad1366b14cfc20e0367f3ab2f3c5541153e7dce6b764689d38315f48a-image.png)

DFS+BFS
先进行一次DFS找出一座岛（值设为2），然后进行BFS找到离DFS找的那座岛的最小距离即可。
### 代码

```cpp
class Solution {
public:
    int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
    void dfs(vector<vector<int>>& A,int x,int y,int& n){
        A[x][y]=2;
        for(int i=0;i<4;i++){
            int newx=x+dir[i][0],newy=y+dir[i][1];
            if(newx<0||newx>=n||newy<0||newy>=n)continue;
            if(A[newx][newy]==2||!A[newx][newy])continue;
            dfs(A,newx,newy,n);
        }
    }
    int shortestBridge(vector<vector<int>>& A) {
        int n = A.size();
        queue<pair<int,int>>q;
        vector<vector<bool>>visit(n,vector<bool>(n));
        bool flag=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(A[i][j]==1&&!flag){
                    flag=1;
                    dfs(A,i,j,n);//找到第一座岛
                }
                if(A[i][j]&1)q.push(make_pair(i,j));//多源BFS找值为2的最小距离
            }
        }
        int distance=-1;
        while(!q.empty()){
            distance++;
            int len = q.size();
            for(int k=0;k<len;k++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(visit[x][y])continue;
                visit[x][y]=1;
                for(int d=0;d<4;d++){
                    int newx = x + dir[d][0];
                    int newy = y + dir[d][1];
                    if(newx<0||newx>=n||newy<0||newy>=n)continue;
                    q.push(make_pair(newx,newy));
                    if(A[newx][newy]==2){
                        return distance;
                    }
                }
            }
        }
        return 1;
    }
};
```