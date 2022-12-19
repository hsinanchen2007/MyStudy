```
func surfaceArea(grid [][]int) int {
    
   n:=0
   for i:=0;i<len(grid);i++{
       for j:=0;j<len(grid[i]);j++{
           a:=grid[i][j]
           if a!=0{
           n+=a*6-(a-1)*2
           if i>=1{
               if grid[i-1][j]<a{
                   n=n-grid[i-1][j]*2
               }else{
                   n=n-2*a
               }
           }
           if j>=1{
               if grid[i][j-1]<a{
               n=n-grid[i][j-1]*2
               }else{
                   n=n-2*a
               }
           }}
       }
   }
   return n
}
```
