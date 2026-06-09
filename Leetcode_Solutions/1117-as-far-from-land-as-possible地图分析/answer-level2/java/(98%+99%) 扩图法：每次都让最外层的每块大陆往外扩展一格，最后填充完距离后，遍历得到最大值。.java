## 扩图法：每次都让最外层的每块大陆往外扩展一格，最后填充完距离后，遍历得到最大值。

![image.png](https://pic.leetcode-cn.com/138c4c944f00566e414d1761cda5f3873672023d5993d92ac33b6b4ade3f5c3b-image.png)


代码如下：

```
class Solution {
        //扩图法：每次都让每块大陆往外扩展一格，最后填充完距离后，得到最大值。

        public int maxDistance(int[][] grid) {

            int k = 1;
            boolean change = true;
            while (change && k <= (grid.length - 1) * (grid.length - 1)){
                change = false;
                for (int i = 0; i < grid.length; i++){
                    for (int j = 0; j < grid[i].length; j++){
                        if (grid[i][j] == k){
                            if (i > 0){
                                if (grid[i-1][j] == 0){
                                    grid[i-1][j] = k + 1;
                                    change = true;
                                }else {
                                    grid[i - 1][j] = Math.min(grid[i - 1][j], k + 1);
                                    change = true;
                                }
                            }
                            if (i < grid.length - 1){
                                if (grid[i+1][j] == 0) {
                                    grid[i+1][j] = k + 1;
                                    change = true;
                                }else {
                                    grid[i + 1][j] = Math.min(grid[i + 1][j], k + 1);
                                    change = true;
                                }
                            }
                            if (j > 0){
                                if ( grid[i][j-1] == 0) {
                                    grid[i][j - 1] = k + 1;
                                    change = true;
                                }else {
                                    grid[i][j - 1] = Math.min(grid[i][j - 1], k + 1);
                                    change = true;
                                }
                            }
                            if (j < grid[i].length - 1){
                                if (grid[i][j+1] == 0){
                                    grid[i][j+1] = k + 1;
                                    change = true;
                                }else {
                                    grid[i][j + 1] = Math.min(grid[i][j + 1], k + 1);
                                    change = true;
                                }
                            }
                        }
                    }
                }
                k++;
            }
            int result = 0;
            for (int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid[i].length; j++) {
                    result = Math.max(result, grid[i][j]);
                }
            }
            return result - 1 == 0 ? -1 : result - 1;
        }
    }
```