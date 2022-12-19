对于很多像我这样逻辑能力差的人来说，直接去想BFS或者DFS或许很难的。
但是如果将道路规格化，再去做这类问题，就变得很简单了。

将道路规格化，就是将这些道路处理为3x3的01数组。（为什么是3x3从图上可以看出来）
然后我们就得到了：
![image.png](https://pic.leetcode-cn.com/850013a02dc16782c5c3a9f459d9f1f48ae901481a6c4f7196d3836dd7098bb4-image.png)转换为![image.png](https://pic.leetcode-cn.com/78773b2920d32ab62629a48cd9cc6835458b71bfcde89d292dac520e0e6c7e53-image.png)
![image.png](https://pic.leetcode-cn.com/0153e979b235efe582d8e40fb60fff582b6ecd4fd9935780c58770c252b53862-image.png)转换为
![image.png](https://pic.leetcode-cn.com/44420fcdef65a428178617cb1bb9b69588a41bef41da017d56db54871816af2b-image.png)
![image.png](https://pic.leetcode-cn.com/028f028daec4808537e0acd712ffec3e10e13fbdfc1f7c6d31e7d85afd07018b-image.png)转换为
![image.png](https://pic.leetcode-cn.com/22f33d6b984f124e94cb8983fdf92f9bdb953f47bafff350bb5f9bf0391ee860-image.png)
依次转换。
我们得到了一个matrix[3*m][3*n]的由01组成的矩阵。
比如
![image.png](https://pic.leetcode-cn.com/7f1216612d36d0d18ccf9d3d550037815bcb4bdb61c0f4b8af682254aa70cbff-image.png)我们得到的矩阵为
![image.png](https://pic.leetcode-cn.com/6ab024aed7bf05d7e714fd7a303a6501976fbaad352ce031c7f30a82cc9e25bf-image.png)
那么我们只需要从第一个3x3矩阵开始，进行DFS或者Bfs都可以。只要满足x/3==m-1&&y/3==n-1即满足条件，返回即可。
代码如下:
```
class Solution {
public:
    vector<pair<int,int>>dir{{0,1},{0,-1},{1,0},{-1,0}};
    bool hasValidPath(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if(m==1&&n==1){
            return true;
        }
        int mm=3*m,nn=3*n;
        vector<vector<int>>matrix(3*m,vector<int>(3*n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(int t=0;t<=2;t++){
                        matrix[3*i+1][3*j+t]=1;
                    }
                }
                else if(grid[i][j]==2){
                    for(int t=0;t<=2;t++){
                        matrix[3*i+t][3*j+1]=1;
                    }
                }
                else if(grid[i][j]==3){
                    matrix[3*i+1][3*j]=1;
                    matrix[3*i+1][3*j+1]=1;
                    matrix[3*i+2][3*j+1]=1;
                }
                else if(grid[i][j]==4){
                    matrix[3*i+1][3*j+1]=1;
                    matrix[3*i+1][3*j+2]=1;
                    matrix[3*i+2][3*j+1]=1;
                }
                else if(grid[i][j]==5){
                    matrix[3*i][3*j+1]=1;
                    matrix[3*i+1][3*j+1]=1;
                    matrix[3*i+1][3*j]=1;
                }
                else if(grid[i][j]==6){
                    matrix[3*i+1][3*j+1]=1;
                    matrix[3*i][3*j+1]=1;
                    matrix[3*i+1][3*j+2]=1;
                }
            }
        }
        queue<pair<int,int>>Q;
        vector<vector<bool>>visit(3*m,vector<bool>(3*n,false));
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(matrix[i][j]){
                    Q.push({i,j});
                    visit[i][j]=true;
                }
            }
        }
        while(!Q.empty()){
            auto p=Q.front();
            Q.pop();
            for(auto d:dir){
                int x=p.first+d.first;
                int y=p.second+d.second;
                if(x>=0&&x<mm&&y>=0&&y<nn&&!visit[x][y]&&matrix[x][y]){
                    visit[x][y]=true;
                    Q.push({x,y});
                    if(x/3==m-1&&y/3==n-1){
                    return true;
                    }
                }
            }
        }
        return false;
    }
};
```
