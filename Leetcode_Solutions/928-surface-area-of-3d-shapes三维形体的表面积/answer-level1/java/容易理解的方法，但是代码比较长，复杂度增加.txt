    把这个型体的三维数据构造出来，有正方体的位置值就为1，因为每个正方体如果周围没有别的正方体的话，它的表面积正常为6，每在它周围出现一个正方体，表面积就会减1，对每一个存在正方体检测它的六个面，最后求和。
```
class Solution {
    public int surfaceArea(int[][] grid) {
    //因为后边三维数组创建是从（1，1，1）开始的，所以要增大容量。
        int[][][] xYZ = new int[52][52][52];
        int res = 0;
        for(int i = 0;i<grid.length;i++){
            for(int j = 0;j<grid[0].length;j++){
                if(grid[i][j]>0){
                    for(int h = 1;h<= grid[i][j];h++){
                        xYZ[i+1][j+1][h] = 1;
                    }
                }
            }
        }
        for(int i=1; i <51;i++){
            for(int j=1; j<51;j++){
                for(int k=1; k <51;k++){
                    if(xYZ[i][j][k] == 1){
                        res+=Test(i,j,k,xYZ);
                    }
                }
            }
        }
        return res;
    }
    public int Test(int x,int y,int z,int xYZ[][][]){
        int area = 6;
        if(xYZ[x-1][y][z] == 1) area--;
        if(xYZ[x][y-1][z] == 1) area--;
        if(xYZ[x][y][z-1] == 1) area--;
        if(xYZ[x+1][y][z] == 1) area--;
        if(xYZ[x][y+1][z] == 1) area--;
        if(xYZ[x][y][z+1] == 1) area--;
        return area;
    }
}
```

