
![image.png](https://pic.leetcode-cn.com/2f67ba09b3d3468e0533775fef3784cf491bb792d38d4cb6972da3719f2a0900-image.png)

public int maxIncreaseKeepingSkyline(int[][] grid) {
    int rlen = grid.length;
    int alen = grid[0].length;
    int[] release = new int[rlen];
    int[] across = new int[alen];
    for(int i=0;i<rlen;i++){
        int[] gchild = grid[i];
        int maxValue = gchild[0];
        for(int j=0;j<alen;j++){
            if(gchild[j]>maxValue) maxValue = gchild[j];
        }
        release[i] = maxValue;
    }
    for(int i=0;i<alen;i++){
        int maxValue = grid[0][i];
        for(int j=0;j<rlen;j++){
            if(grid[j][i]>maxValue) maxValue = grid[j][i];
        }
        across[i] = maxValue;
    }
    int sum = 0;
    for(int i=0;i<rlen;i++){
        int[] gchild = grid[i];
        for(int j=0;j<alen;j++){
            int r = release[i];
            int a = across[j];
            int n = gchild[j];
            if(r>a&&n<a){
                sum = sum + (a-n);
            }else if(a>=r&&n<r){
                sum = sum + (r-n);
            }
        }
    }
    return sum;
}