### 解题思路
照抄的评论大佬的思路 ，运行时发现有个需要注意的地方：判断是否越界时，需要先判断是否到达了行或列的最大值处，不可以先判断是否到达了0行或0列处。否则在计算非行列数相等的二维数组时会发生越界。

### 代码

```java
class Solution {
    public int[] findDiagonalOrder(int[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            return new int[]{};
        }

        int row = matrix.length, col = matrix[0].length;
        int[] res = new int[row * col];

        int r = 0, c = 0;

        for (int i = 0; i < res.length; i++){
            res[i] = matrix[r][c];

            //向上走
            if ((r + c) % 2 == 0){
                //判断是不是向上走走到头了,两个终止条件
                if (c == col - 1) r++;
                else if (r == 0) c++;
                else {
                    r--;
                    c++;
                }
            }else {
                if(r == row - 1) c++;
                else if (c == 0) r++;
                else {
                    r++;
                    c--;
                }
            }
        }
        return res;
    }
}
```