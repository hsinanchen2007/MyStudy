### 解题思路
利用dfs深度优先搜索，将含1的区域进行遍历，最后比较每一块面积得到最大的面积。dfs（vector<vector<int>>&grid,i1,j1）函数的返回值为搜索由该点出发的顶点为1的总数。当区域为0时，返回值为0，越界时返回值为0。

### 代码

```cpp
//深度优先搜索
#include<algorithm>
#include<iostream>
class Solution {
public:        
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int raws = grid.size(); //行
        int cols = grid[0].size(); //列
        int max1 = 0;
        int area = 0;
        for(int i=0;i<raws;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    max1 = max(max1,dfs(grid,i,j));
                }        
            }
        }
        
        return max1;
            
        
    }
    int dfs(vector<vector<int>>& grid,int i1,int j1){
        int x[4] = {0, -1, 0, 1};
        int y[4] = {-1, 0, 1, 0};
        int raws=grid.size();
        int cols=grid[0].size();
        if(i1 < 0 || i1 >= grid.size() || j1 < 0 || j1 >= grid[0].size() || grid[i1][j1] == 0){
            return 0;
        }
        int count = 1;
        int a,b;
        grid[i1][j1]=0;
        for(int k=0;k<=3;k++){
//            dfs(grid,i1+x[k],j1+y[k]);
            count = dfs(grid,i1+x[k],j1+y[k])+count;
        }
        return count;
        
    }
    
};






//此解法只适用于岛屿的每一行的左右全是0，每一列的上下全是0的情况
/*class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int N = grid.size();
//        int M = grid[0].size();
//        if(M>N){
//            N = M;
//        }
        int data[100][4]={-1};//按顺序分别是最左最右最上最下
        int columnorline;
        int left = 0,right = 0,up = 0,down = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){//寻找边界
                if(grid[i][j] == 0){
                    if(data[i][0] == -1){  //遇到最左面的将data赋值为列数
                        data[i][0]== j;
                    }
                    if(data[j][2] == -1){
                        data[j][2] = i;    //右边界
                    }
                    data[i][1] = j;     //上边界
                    data[j][3] = i;     //下边界
                }
                
            }

        }
        int area = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(j>data[i][0] && j<data[i][1] && i>data[j][2] && i<data[j][3]){
                    area++;
                }
            }
        }
        return area;
    }
};*/

```