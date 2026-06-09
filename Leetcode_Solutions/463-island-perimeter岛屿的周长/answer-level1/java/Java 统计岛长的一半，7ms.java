对于一行来说，有左必有右；
对于一列来说，有上必有下。
只需统计每个为1的格子的上和左的长度，总长就是它的二倍。
```
class Solution {
    public int islandPerimeter(int[][] grid) {
        int ans=0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]==1){
                    if(i==0||grid[i-1][j]==0){//上
                        ans++;
                    }
                    if(j==0||grid[i][j-1]==0){//左
                        ans++;
                    }
                }
            }
        }
        return ans<<1;
    }
}
```
