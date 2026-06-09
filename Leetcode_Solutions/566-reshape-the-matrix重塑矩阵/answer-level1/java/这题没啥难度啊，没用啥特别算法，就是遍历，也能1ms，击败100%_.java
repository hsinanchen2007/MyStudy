### 解题思路
能否重塑，只有一个判断条件，就是原始矩阵的row*col是否等于新矩阵的r*c。
不符合就直接输出原始矩阵。如果符合条件，那就直接按行列遍历原始矩阵，然后依次填到新矩阵里即可。
新矩阵采用自增式遍历，col到头就换行。

### 代码

```java
class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        if (nums.length * nums[0].length != r * c) return nums;
        int[][] ans = new int[r][c];
        int row = 0;
        int col = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < nums[0].length; j++) {
                ans[row][col] = nums[i][j];
                if (col == c - 1) {
                    row++;
                    col = 0;
                } else {
                    col++;
                };
            }
        };
        return ans;
    }
}
```