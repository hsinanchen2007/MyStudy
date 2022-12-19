### 解题思路
此处撰写解题思路

### 代码

```cpp
int value;
class Solution {
public:
    void bfs(vector<vector<int>>& grid,int l,int r){
        
        if(l==grid.size())return;
        if(r==grid[0].size())return;
        if(l<0||r<0)return;
        if(grid[l][r]==0)return;
        if(grid[l][r]==1){
            value++;
            grid[l][r]=0;
        }
        bfs(grid,l+1,r);
        bfs(grid,l,r+1);
        bfs(grid,l,r-1);
        bfs(grid,l-1,r);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        value=0;
        set<int> res;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                bfs(grid,i,j);
                res.insert(value);
                value=0;
            }
        }
        set<int>::iterator it;
        it=res.end();
        it--;
        return *it;
    }
};
```