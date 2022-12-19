然而无论哪种解法都要嵌套循环完整遍历...

解法1：

```
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        
        int x = grid[0].size();//地图的横轴长度
        int y = grid.size();//地图的纵轴长度
        
        int C=0;
        
        for(int i=0; i<y; i++){
            
            for(int j=0; j<x; j++){
                
                if(grid[i][j]==1){
                    
                    C+=4;//一块陆地的周长为4
                    
                    //周边四个方向每个方向若有其它陆地相邻，则周长减1
                    if(i-1>=0 && grid[i-1][j]==1)
                        C-=1;
                    if(i+1<y && grid[i+1][j]==1)
                        C-=1;
                    if(j-1>=0 && grid[i][j-1]==1)
                        C-=1;
                    if(j+1<x && grid[i][j+1]==1)
                        C-=1;
                    
                }
                

            }
        }
        
        
        return C;
        
    }
};
```
解法2：

```
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        
        int x = grid[0].size();//地图的横轴长度
        int y = grid.size();//地图的纵轴长度
        
        int C=0;
        
        for(int i=0; i<y; i++){
            
            for(int j=0; j<x; j++){
                
                if(grid[i][j]==1){
                    
                    //统计岛屿任意相邻两个朝向的面数和
                    if(i-1<0 || grid[i-1][j]==0)
                        C+=1;
                    //if(i+1>y || grid[i+1][j]==0)
                        //C+=1;
                    if(j-1<0 || grid[i][j-1]==0)
                        C+=1;
                    //if(j+1>x || grid[i][j+1]==0)
                        //C+=1;
                    
                }
            }
        }
        
        
        return C*2;//统计出来的面数×2就是总周长
        
    }
};
```
