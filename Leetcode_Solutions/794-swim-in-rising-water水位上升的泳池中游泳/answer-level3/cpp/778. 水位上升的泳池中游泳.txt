### 解题思路
二分逼近正确答案
用dfs验证是否能到终点
注意：不能用回溯，否则会超时，因为之前走过的路径到达不了，再走一次也不可能到达
### 代码

```cpp
class Solution {
public:
    int next[4][2]={-1,0,0,1,1,0,0,-1};
    int book[51][51];
    int f;
    void dfs(int x,int y,int h,vector<vector<int>>& grid,int n){
        int xx,yy;
        for(int k=0;k<4;k++){
            xx=x+next[k][0];
            yy=y+next[k][1];
            if(xx<0||xx>=n||yy<0||yy>=n||book[xx][yy]==1||grid[xx][yy]>h) continue;
            if(xx==n-1&&yy==n-1){
                f=1;return ;
            }
            book[xx][yy]=1;
            dfs(xx,yy,h,grid,n);if(f) return ;
        }
    }
    int swimInWater(vector<vector<int>>& grid) {
        int l=grid[0][0],r=50*50-1,mid;
        int n=grid.size();
        while(l<r){
            mid=(l+r)/2;
            f=0;memset(book,0,sizeof(book)); book[0][0]=1;
            dfs(0,0,mid,grid,n);
            if(f) r=mid;
            else l=mid+1;
        }
        return r;
    }
};
```