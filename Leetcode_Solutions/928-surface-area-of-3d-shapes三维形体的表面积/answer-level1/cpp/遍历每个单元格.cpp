### 解题思路
此处撰写解题思路
1.由于网格有边界，处理起来需要考虑边界的很多情况
2.将nxn的矩阵的周围加上一圈0，扩展成n+2 x n+2的矩阵，这样对所有的元素的处理都相同了
3.遍历每个存在正方体柱的单元格，如果存在，加上上面和下面的面积；与周围的四个单元格比较，如果比周围的单元格高，加上露出来的表面积
### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int result=0;
        int n = grid.size();
        expand_grid(grid);//expand grid to n+2*n+2
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(grid[i][j]!=0){result+=2;}//plus bottom and top
                
                if(grid[i][j]>grid[i][j-1]){
                    result += grid[i][j]-grid[i][j-1];
                }
                if(grid[i][j]>grid[i][j+1]){
                    result+=grid[i][j]-grid[i][j+1];
                }
                if(grid[i][j]>grid[i-1][j]){
                    result+= grid[i][j]-grid[i-1][j];
                }                                      
                if(grid[i][j]>grid[i+1][j]){
                    result+=grid[i][j]-grid[i+1][j];
                }
                
            }
        }
        return result;
    }
private:
    void expand_grid(vector<vector<int>>& grid){
        int n = grid.size();
        vector<int> ints(n+2,0);

        for(auto it=grid.begin();it!=grid.end();it++){
            (*it).push_back(0);
            (*it).insert((*it).begin(),0);
        }
        grid.push_back(ints);
        grid.insert(grid.begin(),ints);


    }

private:

};
```