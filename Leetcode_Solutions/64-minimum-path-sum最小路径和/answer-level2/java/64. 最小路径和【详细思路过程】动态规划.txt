**思路：**
&emsp;首先想到可以使用动态规划来解决，对于每一个状态都是由于上面或者左边的值加上当前值。

**过程：**
&emsp;1. 创建 一个dp数组，状态转移方程，dp[i][j] = Math.min(dp[i][j-1]+grid[i][j],dp[i-1][j]+grid[i][j])
&emsp;2. 考虑边界状态
&emsp;&emsp;2.1 由于状态转移必须来自上一个状态，因此第一个状态dp[0][0]初始化为grid[0][0]
&emsp;&emsp;2.2 最上一行的格子的上一个状态只可能来自左边
&emsp;&emsp;2.2 最左一列的格子的上一个状态只可能来自上面
&emsp;3. 循环，需要注意的是当i为0时候j不能为0，避免数组越界

&emsp;根据以上思路写代码：
```
 public int minPathSum(int[][] grid) {
        //思路：首先想到可以使用动态规划来解决，对于每一个状态都是由于上面或者左边的值加上当前值
        //过程：
        /* 1、创建 一个dp数组，状态转移方程，dp[i][j] = Math.min(dp[i][j-1]+grid[i][j],dp[i-1][j]+grid[i][j])
           2、考虑边界状态
                2.1 由于状态转移必须来自上一个状态，因此第一个状态dp[0][0]初始化为grid[0][0]
                2.2 最上一行的格子的上一个状态只可能来自左边
                2.2 最左一列的格子的上一个状态只可能来自上面
            3、循环，需要注意的是当i为0时候j不能为0，避免数组越界
        * */


        //只有1格,要自主测试一下返回0还是返回这个格子的值作为开销
        if (grid.length <= 1 && grid[0].length <= 1) {
            return grid[0][0];
        }

        int[][] dp = new int[grid.length][grid[0].length];
        dp[0][0] = grid[0][0];

        for (int i = 0; i < grid.length; i++) {
            for (int j = i==0?1:0; j < grid[0].length; j++) {

                if (i==0){
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                }else if (j==0){
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                }else {
                    dp[i][j] = Math.min(dp[i][j - 1] + grid[i][j], dp[i - 1][j] + grid[i][j]);
                }
            }
        }

        return dp[grid.length - 1][grid[0].length - 1];
    }
```

&emsp;掌握二维的动态规划方式后，很容易理解使用一维数组来进行动态规划，我们可以知道从上到下每一行的元素，只和其左边和上面有关，我们只需要逐行遍历累加即可。
```
    public int minPathSum(int[][] grid) {
        //只有1格,要自主测试一下返回0还是返回这个格子的值作为开销
        if (grid.length <= 1 && grid[0].length <= 1) {
            return grid[0][0];
        }
        
        //在原数组进行递归,使用一个一维数组记录上一行
        int[] preRow = new int[grid[0].length];

        //遍历每一行
        for (int i = 0; i < grid.length; i++) {
            if (i != 0) {
                preRow = grid[i-1].clone();
            }
            //遍历每一列
            for (int j = i == 0 ? 1 : 0; j < grid[i].length; j++) {
                if (i == 0) {
                    //第一行元素只来自左边
                    grid[i][j] = grid[i][j - 1] + grid[i][j];
                } else if (j == 0) {
                    //第一列只来自上面
                    grid[i][j] = preRow[j] + grid[i][j];
                } else {
                    //选择上面或者左边的最小值
                    grid[i][j] = Math.min(grid[i][j - 1] + grid[i][j], preRow[j] + grid[i][j]);
                }
            }
        }

        return grid[grid.length - 1][grid[0].length - 1];
    }
```
&emsp;总结一下，动态规划可以使用二维，同时我们要考虑空间复杂度，是否要存储全部，可以使用滚动变量或者像第二种方法一样使用一维数组，迭代这个数据即可。


