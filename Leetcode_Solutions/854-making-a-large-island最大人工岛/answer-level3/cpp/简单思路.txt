### 解题思路
1 计算各岛屿面积；
2 将岛屿值grid改为岛屿面积，并用二维数组is_same存储是否为同一岛屿，并用flag存储值为0的节点周围的岛屿数（0-4，可能为同一岛屿）；
3 遍历所有节点，求得最大值。
注：将一个0改为1，最大可得岛屿面积为{上方(岛屿面积)+下方+左方+右方+1}（去除挑其中的重复岛屿），根据is_same可判断两节点是否为同一岛屿。
一些细节不再阐述，见谅。
### 代码

```cpp
// static const auto io_sync_off = []()
// {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     return nullptr;
// }();
class Solution {
private:
    void fill_grid(vector<vector<int>>& grid,int i,int j,int res,vector<vector<int>>& flag,vector<vector<int>>& is_same,int zz){
        if(grid[i][j]!=0 && grid[i][j]!=res){
            grid[i][j]=res;
            is_same[i][j]=zz;
            if(i>0){
                fill_grid(grid,i-1,j,res,flag,is_same,zz);
            }
            if(j>0){
                fill_grid(grid,i,j-1,res,flag,is_same,zz);
            }
            if(i<grid.size()-1){
                fill_grid(grid,i+1,j,res,flag,is_same,zz);
            }
            if(j<grid[0].size()-1){
                fill_grid(grid,i,j+1,res,flag,is_same,zz);
            }
        }
        if(grid[i][j]==0){
            flag[i][j]++;
        }
    }
    void find_max(vector<vector<int>>& grid,int i,int j,int& res){
        if(grid[i][j]==1){
            grid[i][j]=-1;
            res++;
            if(i>0){
                find_max(grid,i-1,j,res);
            }
            if(j>0){
                find_max(grid,i,j-1,res);
            }
            if(i<grid.size()-1){
                find_max(grid,i+1,j,res);
            }
            if(j<grid[0].size()-1){
                find_max(grid,i,j+1,res);
            }
        }
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int res=0,maxx=0,zz=0;
        vector<vector<int>> flag=grid,is_same=grid;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                flag[i][j]=0;
                is_same[i][j]=-1;
            }
        }bool have_1=false;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                maxx=0;
                if(grid[i][j]==1){
                    find_max(grid,i,j,maxx);
                    fill_grid(grid,i,j,maxx,flag,is_same,zz);
                    zz++;
                    res=max(res,maxx);
                    have_1=true;
                }
            }
        }
        if(!have_1){
            return 1;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(flag[i][j]>0){
                    maxx=1;
                    int zz1=-1,zz2=-1,zz3=-1;
                    if(i>0){
                        maxx+=grid[i-1][j];
                        zz1=is_same[i-1][j];
                    }
                    if(j>0){
                        if(is_same[i][j-1]!=zz1){
                            maxx+=grid[i][j-1];
                            zz2=is_same[i][j-1];
                        }
                    }
                    if(i<grid.size()-1){
                        if(is_same[i+1][j]!=zz1 &&is_same[i+1][j]!=zz2){
                            maxx+=grid[i+1][j];
                            zz3=is_same[i+1][j];
                        }
                    }
                    if(j<grid[0].size()-1){
                        if(is_same[i][j+1]!=zz1 && is_same[i][j+1]!=zz2 && is_same[i][j+1]!=zz3){
                            maxx+=grid[i][j+1];
                        }
                    }
                    res=max(res,maxx);
                }
            }
        }
        return res;
    }
};
```