### 解题思路
这是一个典型的可用动态规划来解决的问题，可以先以递归的思路进行分析。
首先，定义函数f(i,j)表示到达坐标为(i,j)的格子时能拿到的礼物价值总和的最大值。根据题目要求，我们只有通过右移或下移两种方式来到达矩阵右下角的格子即通过(i+1,j)或(i,j+1)。
于是我们可以反推到达(i,j)格子的上一步可能为(i-1,j)或（i,j-1），综上所述得到f(i,j)=max(f(i-1,j),f(i,j-1))+gift[i,j],其中gift[i,j]代表(i,j)格子中的礼物价值。
我们在计算中需要定义一个中间二维数组来存储用于存储到达各个节点时所能获取的礼物最大价值。
### 代码

```java
class Solution {
    public int maxValue(int[][] grid) {
    
        if (grid == null || grid.length <= 0 || grid[0].length <= 0){
            return 0;
        }
        int rows = grid.length;
        int cols = grid[0].length;
        //定义中间二位数组
        int[][] maxValues = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                //定义left，up分别用来存储上一步计算所得的两个最大值
                //两个可能的上一步分别位于当前格子的左边和上边
                int left = 0;
                int up = 0;
                if (i > 0){
                    up = maxValues[i-1][j];
                }
                if (j > 0){
                    left = maxValues[i][j-1];
                }
                //计算的到当前格子可得礼物最大价值
                maxValues[i][j] = Math.max(up,left) + grid[i][j];
            }
        }
        //最终返回中间结果矩阵右下角数值即为题目结果
        return maxValues[rows-1][cols-1];
    }
}
```