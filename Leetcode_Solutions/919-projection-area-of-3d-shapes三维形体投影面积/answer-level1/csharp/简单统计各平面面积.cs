```
public int ProjectionArea(int[][] grid) {
        var sum=0;
        
        var xl=grid.Length;
        var yl=grid[0].Length;
        
        var xz=new int[xl];
        var yz=new int[yl];
        
        for(var i=0;i<xl;i++){
            for(var j=0;j<yl;j++){
                if(grid[i][j]>0){
                   sum++;
                    if(xz[i]<grid[i][j]){
                        xz[i]=grid[i][j];
                    }
                    if(yz[j]<grid[i][j]){
                        yz[j]=grid[i][j];
                    }
                }
            }
        }
        
        foreach(var t in xz){
            sum+=t;
        }
        foreach(var t in yz){
            sum+=t;
        }
        return sum;
    }
```
