### 解题思路
此处撰写解题思路
加了点注释
### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        //右 下 左 上
        int[] dr = new int[]{0, 1, 0, -1};
        int[] dc = new int[]{1, 0, -1, 0};

        int N = grid.length;
        int ans = 0;
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                //判断(i,j)处是否有立方体
                if(grid[i][j] > 0){
                    //顶底面贡献了2
                    ans += 2;
                    for(int k = 0; k < 4; k++){
                        int r = i + dr[k];
                        int c = j + dc[k];
                        int nv = 0;
                        if(r >= 0 && r < N && c >= 0 && c < N)
                            //计算出四周立方体的一个侧面的面积
                             nv = grid[r][c];
                        //计算出(i,j)这个位置立方体的一个侧面贡献出了多少
                        ans += Math.max(grid[i][j] - nv, 0);
                    }
                }
            }
        }
        return ans;
    }
}
```