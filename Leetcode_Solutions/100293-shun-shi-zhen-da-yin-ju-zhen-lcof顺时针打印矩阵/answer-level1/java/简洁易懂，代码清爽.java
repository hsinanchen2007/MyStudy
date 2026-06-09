### 解题思路
顺时针遍历，注意边界

### 代码

```java
class Solution {
    public int[] spiralOrder(int[][] matrix) {
        int m = matrix.length;
        if(m==0){
            return new int[]{};
        }
        int n = matrix[0].length;
        int cnt=0;
        int[] res = new int[m*n];

        int r1 = 0, r2 = m - 1, c1 = 0, c2 = n - 1;
        //(r1,c1)左上角的点，(r2,c2)右下角
        while (r1 <= r2 && c1 <= c2) {
            for (int i = c1; i <= c2; i++)
                 res[cnt++]=matrix[r1][i];
            for (int i = r1 + 1; i <= r2; i++)
                 res[cnt++]=matrix[i][c2];
            if (r1 != r2)
                for (int i = c2 - 1; i >= c1; i--)
                     res[cnt++]=matrix[r2][i];
            if (c1 != c2)
                for (int i = r2 - 1; i > r1; i--)
                     res[cnt++]=matrix[i][c1];
            r1++; r2--; c1++; c2--;//左上角右下角元素移动
        }
        return res;

    }

}
```