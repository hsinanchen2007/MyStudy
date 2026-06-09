>1.计算每个柱体总表面积
>2.减掉和周围重叠的部分（提前将周围需要减掉的一并算入）
>3.清空当前位置
```
class Solution {
public:
    int area(vector<vector<int>>& grid,int i,int j){
        if(grid[i][j]==0)return 0;
        int ans = grid[i][j]*6 - (grid[i][j]-1)*2;
        int is[4]{0,0,-1,1};
        int js[4]{1,-1,0,0};
        for(int k=0;k<4;k++){
            if(i+is[k]==grid.size() || i+is[k]<0 || j+js[k]==grid.size() || j+js[k]<0) continue;
            ans-=min(grid[i+is[k]][j+js[k]],grid[i][j])*2;
        }
        grid[i][j]=0;
        return ans;
    }
    int surfaceArea(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans+=area(grid,i,j);
            }
        }
        return ans;
    }
};
```