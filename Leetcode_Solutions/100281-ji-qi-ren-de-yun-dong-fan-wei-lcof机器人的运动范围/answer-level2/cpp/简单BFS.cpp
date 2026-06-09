### 解题思路
首先这题不能暴力判断每个格子满不满足题目条件，因为有的格子过不去，因此需要搜索
其实就是BFS模板。。
不动脑子的话，无脑上下左右走就完事了（反正数据范围小）

### 代码

```cpp
class Solution {
public:
    struct node{
        int x,y;
    };
    int vis[105][105];
    int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    int count(int x,int y){
        int ans=0;
        while(x){
            ans+=x%10;
            x/=10;
        }
        while(y){
            ans+=y%10;
            y/=10;
        }
        return ans;
    }
    int movingCount(int m, int n, int k) {
        queue<node> q;
        q.push(node{0,0});
        int ans=0;
        vis[0][0]=1;
        while(q.size()){
            node q1=q.front();
            q.pop();
            ans++;
            for(int i=0;i<4;i++){
                int dx=q1.x+dir[i][0];
                int dy=q1.y+dir[i][1];
                if(dx>=0&&dx<m&&dy>=0&&dy<n&&!vis[dx][dy]&&count(dx,dy)<=k){
                    vis[dx][dy]=1;
                    q.push(node{dx,dy});
                }
            }
        }
        return ans;
    }
};
```