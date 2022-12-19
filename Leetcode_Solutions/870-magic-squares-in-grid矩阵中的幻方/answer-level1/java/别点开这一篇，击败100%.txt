### 解题思路
方法挺笨的，基本是简单的相加

有几点需要注意的是：
1. 幻方里面的元素不能有重复的（1-9之间），因此需要检查元素重复的情况
2. 通过计算得出中心的元素一定等于5，所以可以先做这个判断


### 代码

```java
class Solution {
    public int numMagicSquaresInside(int[][] grid) {
        int l1 = grid.length, l2 = grid[0].length;
        int ans = 0;

        if(l1 < 3 || l2 < 3) return ans;

        for(int i = 0; i < l1 - 2; i++){
            for(int j = 0; j < l2 - 2; j++){
                if(grid[i + 1][j + 1] != 5) continue;

                int row1 = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
                int row2 = grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2];
                int row3 = grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];

                int col1 = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
                int col2 = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1];
                int col3 = grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2];

                int cos1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
                int cos2 = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];

                if(row1 != 15 
                    || row2 != 15 
                    || row3 != 15 
                    || col1 != 15 
                    || col2 != 15 
                    || col3 != 15
                    || cos1 != cos2) continue;

                int[] nums = {grid[i][j], grid[i][j + 1], grid[i][j + 2],
                                grid[i + 1][j], grid[i + 1][j + 1], grid[i + 1][j + 2],
                                grid[i + 2][j], grid[i + 2][j + 1], grid[i + 2][j + 2]};

                int[] temp = new int[16];
                for(int v : nums) temp[v]++;
                for(int h = 1; h <= 9; h++){
                    if(temp[h] != 1){
                        ans--;
                        break;
                    }
                }
                
                ans ++;
            }
        }
        return ans;
    }
}
```