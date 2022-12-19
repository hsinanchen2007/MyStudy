### 解题思路
此处撰写解题思路
BFS
### 代码

```cpp
class Solution {
public:
    struct node{
        int x,y;
        node(int xx,int yy):x(xx),y(yy){}
    };
    int m,n;
    int a[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    vector<int> v;
    bool visit[1010][1010]={false};
    bool judge(int x,int y,vector<vector<int>>& land){
        if(x<0||x>=m||y<0||y>=n)
            return false;
        if(visit[x][y]==true||land[x][y]!=0){
            return false;
        }
        return true;
    }
    void bfs(int x,int y,vector<vector<int>>& land){
        visit[x][y]=true;
        queue<node> q;
        node no=node(x,y);
        q.push(no);
        int ans=1;
        while(!q.empty()){
            node top=q.front();
            q.pop();
            for(int i=0;i<8;++i){
                int xx=top.x+a[i][0];
                int yy=top.y+a[i][1];
                if(judge(xx,yy,land)){
                    q.push(node(xx,yy));
                    visit[xx][yy]=true;
                    ans++;
                }
            }
        }
        v.push_back(ans);
    }
    vector<int> pondSizes(vector<vector<int>>& land) {
         m=land.size();
         n=land[0].size();
         int sum=0;
         for(int i=0;i<m;++i){
             for(int j=0;j<n;++j){
                 if(judge(i,j,land)){
                     bfs(i,j,land);
                 }
             }
         }
         sort(v.begin(),v.end());
         return v;
    }
};
```