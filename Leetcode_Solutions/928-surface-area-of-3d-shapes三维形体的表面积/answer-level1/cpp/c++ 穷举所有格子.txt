```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        //最终表面积，为每个格子的立方体贡献的表面积之和
        //每个格子，贡献的上下底面积，恒为2
        //每个格子，贡献的侧面积：四个方向分别计算。如果格子比当前方向邻居高，就贡献了侧面积
        int ultiArea=0;
        int udlr[][2]={-1,0, 1,0, 0,-1, 0,1};
        #define inGrid(i,j,arrname) ((i)>=0&&(i)<arrname.size()&&(j)>=0&&(j)<arrname[0].size())
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size();j++){
                if(grid[i][j])
                    ultiArea+=2;
                for(int k=0; k<4; k++){
                    if(!inGrid(i+udlr[k][0],j+udlr[k][1],grid))
                        ultiArea+=grid[i][j];
                    else if(grid[i][j]>grid[i+udlr[k][0]][j+udlr[k][1]])
                        ultiArea+=grid[i][j]-grid[i+udlr[k][0]][j+udlr[k][1]];
                }
            }
        }
        return ultiArea;
   
```
