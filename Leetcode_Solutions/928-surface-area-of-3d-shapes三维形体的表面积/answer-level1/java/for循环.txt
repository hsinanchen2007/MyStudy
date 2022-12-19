```
class Solution {
    public int surfaceArea(int[][] grid) {
        if(grid==null)return 0;
        int surfaces=0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                int v=grid[i][j];
                if(v!=0)
                surfaces+=v*6-2*(v-1);
            }
        }
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length-1;j++){
                int min=Math.min(grid[i][j],grid[i][j+1]);
                surfaces=surfaces-min*2;
            }
        }
        for(int i=0;i<grid[0].length;i++){
            for(int j=0;j<grid.length-1;j++){
                int min=Math.min(grid[j][i],grid[j+1][i]);
                surfaces=surfaces-min*2;
            }
        }
        return surfaces;
    }
}
```
