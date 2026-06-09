```java
class Solution {
    int max;
    public int maxAreaOfIsland(int[][] grid) {
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                max=Math.max(max,scan(grid,i,j,0));
            }
        }
        return max;
    }

   //最主要的思路就是当扫描到某个i，j为1时候，_tempMax+1
   //接着扫描前后左右,直到出界和碰到为0就返回。这个过程就是递归的2要素
   //1.返回条件是什么
   //2.继续递归的时候新的输入参数变化
    public int scan(int[][] grid,int i,int j,int _tempMax){
          if(i<0||i>=grid.length||j<0||j>=grid[0].length){              
              return _tempMax;
          }else{
              if(grid[i][j]==0){
                 return _tempMax;
              }else{
                 _tempMax++; 
                 grid[i][j]=0;
                 _tempMax= scan(grid,i+1,j,_tempMax);               
                 _tempMax= scan(grid,i-1,j,_tempMax); 
                 _tempMax= scan(grid,i,j+1,_tempMax); 
                 _tempMax= scan(grid,i,j-1,_tempMax); 
                 return _tempMax;
              }
          }  
    }
}
```
