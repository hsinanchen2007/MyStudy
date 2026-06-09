
### 减重合部分

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int res = 0;
        int upbot = 0;
        int side = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] > 0){
                    res += grid[i][j]*6;    //所有方块表面积为 6*n
                    upbot += ((grid[i][j]-1)*2);  //上下接触减去 2*(高度-1) 
                    side += mysum(grid,i,j);  //左右的等于相邻那边小的那个的高度
                }
            }
        }
        return res - upbot - side;
    }
    int mysum(vector<vector<int>>& grid ,int i,int j){
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int sum = 0;
        for(int k=0;k<4;k++){
            int x = i+dir[k][0];
            int y = j+dir[k][1];
            if(x>=0&&y>=0&&x<grid.size()&&y<grid[0].size()&&grid[x][y]>0){
                sum += min(grid[x][y],grid[i][j]);
            }
        }
        return sum;
    }
};
```


### 直接计算
```
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int N=grid.size();
        int res=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]==0) continue;//跳过这一次的计算
                res+=2; //底面和上面
                if(i==0) res+=grid[i][j]; //多出的表面积，边缘直接加，中间减一下
                else{
                    if(grid[i][j]-grid[i-1][j]>0) res+=grid[i][j]-grid[i-1][j]; 
                }
                if(i==N-1) res+=grid[i][j];
                else{
                    if(grid[i][j]-grid[i+1][j]>0) res+=grid[i][j]-grid[i+1][j];
                }
                if(j==0) res+=grid[i][j];
                else{
                    if(grid[i][j]-grid[i][j-1]>0) res+=grid[i][j]-grid[i][j-1];
                }
                if(j==N-1) res+=grid[i][j];
                else{
                    if(grid[i][j]-grid[i][j+1]>0) res+=grid[i][j]-grid[i][j+1];
                }
            }
        } 
        return res;
    }
};
```
