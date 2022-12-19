### 解题思路
题目，看起来很难，实际上类似走迷宫，用dfs即可解决，不多说

### 代码

```cpp
class Solution {
    int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int size_row = image.size();
        int size_col = image[0].size();
        vector<vector<int>> vis(size_row,vector<int>(size_col,0));
        int safe_color = image[sr][sc];
        dfs(image,sr,sc,newColor,vis,safe_color);
        return image;

    }
    void dfs(vector<vector<int>>& image,int sr,int sc,int newColor,vector<vector<int>>& vis,int safe_color){
        int size_row = image.size();
        int size_col = image[0].size();
       // vector<vector<int>> vis(size_row,vector<int>(size_col,0));
       // int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        if(image[sr][sc]!=newColor&&vis[sr][sc]==0){
            image[sr][sc]=newColor;
            vis[sr][sc]=1;
            for(int i=0;i<4;i++){
                int next_sr = sr + next[i][1];
                int next_sc = sc + next[i][0];
                if(next_sr<size_row&&next_sr>=0&&next_sc<size_col&&next_sc>=0){
                    if(vis[next_sr][next_sc]==0&&image[next_sr][next_sc]==safe_color){
                         dfs(image,next_sr,next_sc,newColor,vis,safe_color);
                    }
                }
            }

        }
        return;
    }
};
```