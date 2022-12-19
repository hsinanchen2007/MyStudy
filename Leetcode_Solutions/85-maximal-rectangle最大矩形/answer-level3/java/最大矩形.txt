### 解题思路
1. 一开始想到一个动态规划，可惜写了半天是个错的。。。
2. 不看题解，联想不到上一题，哭。
3. 通过将矩阵分解，每一行的结果都可由上一题解决，因此复用栈方法，循环行数次，得出最大结果。
4. 下面代码的动态规划是正确的解法。计算当前行时，复用上一行的结果。对于每一个点，基于它的最大矩形有对于的左右和高边界，更新每个位置的左右高届，得到最终结果。

### 代码

```java
class Solution {
    public int maximalRectangle(char[][] matrix) {
        if(matrix == null || matrix.length == 0 || matrix[0] == null || matrix[0].length == 0)
            return 0;
        int m = matrix.length, n = matrix[0].length, maxarea = 0;
        int[] lefts = new int[n]; //默认每个点的左界都为0，即最大
        int[] heights = new int[n];
        int[] rights = new int[n];

        Arrays.fill(rights, n);//默认每个点的右界都为n，即最大
        for(int i = 0; i < m; i++){
            int cur_left = 0, cur_right = n;
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1') heights[j] += 1;
                else heights[j] = 0;
            }

            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1') lefts[j] = Math.max(lefts[j], cur_left);//遇到1时，将lefts[j]更新为最新左界cur_left.
                else{lefts[j] = 0; cur_left = j + 1;}//当遇到0时，将lefts[j]的左界设为最左，即最大，因为这一行这个列的height为0，下一行这列的左界不再受这一行左界的影响。。这一行的当前左界更新为j+1.
            }

            for(int j = n - 1; j >= 0; j--){//从右向左遍历，是因为右界和左界思路相反。
                if(matrix[i][j] == '1') rights[j] = Math.min(rights[j], cur_right);//min
                else{rights[j] = n; cur_right = j;}//其他和左界更新思路一样。
            }

            for(int j = 0; j < n; j++){//每行的左右高届确定后。更新最大面积
                maxarea = Math.max(maxarea, heights[j] * (rights[j] - lefts[j]));
            }
        }
        return maxarea;
    }
}
```