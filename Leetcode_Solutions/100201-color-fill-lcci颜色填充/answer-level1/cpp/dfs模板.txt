### 解题思路
简单的dfs

### 代码

```cpp
class Solution {
public:
    int vis[60][60];
    int way[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    int m,n;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        m=image.size();
        n=image[0].size();
        memset(vis,0,sizeof(vis));
        dfs(sr,sc,image,image[sr][sc],newColor);
        return image;
    }
    void dfs(int x,int y,vector<vector<int>>& image,int target,int newColor){
        image[x][y]=newColor;
        for(int i=0;i<4;i++){
            int xd=x+way[i][0];
            int yd=y+way[i][1];
            if(xd>=0&&xd<m&&yd>=0&&yd<n&&vis[xd][yd]==0&&image[xd][yd]==target){
                vis[xd][yd]=1;
                dfs(xd,yd,image,target,newColor);
                vis[xd][yd]=0;
            }
        }
    }
};
```