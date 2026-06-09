


```
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        
        int x = grid[0].size();//x轴的最大尺寸
        int y = grid.size();//y轴的最大尺寸
        
        int xy = 0;//xy面上的投影，等于数组中大于0的元素的个数
        int xz = 0;//xz面上的投影，等于每列最大元素的和
        int yz = 0;//yz面上的投影，等于每行最大元素的和

        
        for(int i=0; i<y; i++){
            
            int x_max = 0;//找出每行最大元素
            int y_max = 0;//找出每列最大元素
            
            for(int j=0; j<x; j++){
                
                if(grid[i][j]>0)
                    xy++;
                if(grid[i][j]>x_max)
                    x_max = grid[i][j];
                if(grid[j][i]>y_max)
                    y_max = grid[j][i];
            }
            
            yz += x_max;
            xz += y_max;
        }
        
        
        return xy+xz+yz;//返回三个投影面积的总和
    }
};
```
