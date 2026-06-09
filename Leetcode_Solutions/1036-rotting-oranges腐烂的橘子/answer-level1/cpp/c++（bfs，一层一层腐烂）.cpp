![微信图片_20200305124047.png](https://pic.leetcode-cn.com/e86f428413b1737656f70aa330c010a17e1b37d8c56b68b5c7fe838582c5246e-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200305124047.png)

```
class Solution {
    vector<vector<int>> rotting;
    bool rotted=false;
    int fresh=0;
    void ins(vector<vector<int>>& grid, int i, int j){
        rotting.push_back({i,j});
        rotted=true;
        fresh--;
        grid[i][j]=2;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int begin=0,res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2) rotting.push_back({i,j}),rotted=true;
                if(grid[i][j]==1) fresh++;
            }
        }
        while(rotted){
            rotted=false;
            int end=rotting.size();
            for(int i=begin;i<end;i++){
                if(rotting[i][0]-1>=0 && grid[rotting[i][0]-1][rotting[i][1]]==1) ins(grid, rotting[i][0]-1, rotting[i][1]);
                if(rotting[i][0]+1<=grid.size()-1 && grid[rotting[i][0]+1][rotting[i][1]]==1) ins(grid, rotting[i][0]+1, rotting[i][1]);
                if(rotting[i][1]-1>=0 && grid[rotting[i][0]][rotting[i][1]-1]==1) ins(grid, rotting[i][0], rotting[i][1]-1);
                if(rotting[i][1]+1<=grid[0].size()-1 && grid[rotting[i][0]][rotting[i][1]+1]==1) ins(grid, rotting[i][0], rotting[i][1]+1);
            }
            begin=end;
            if(rotted) res++;
            else break;
        }
        return fresh?-1:res;
    }
};
```
