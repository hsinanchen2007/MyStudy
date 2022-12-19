## 思路：

直接对每条对角线进行遍历，i代表第i行，j代表第j列, k代表着第几条对角线。  
主要分为两种情况:
1. 对角线方向是从左下到右上(k % 2 == 0, 用位操作就是 (k & 1) == 0)  
   - 坐标遍历顺序为(i, j) -> (i-1, j+1)  
   - 终止条件: i < 0 (i 小于最小行号) || j >= n (j 超过最大列号)
   
2. 对角线方向是从右上到左下(k % 2 == 1)  
   - 坐标遍历顺序为(i, j) -> (i+1, j-1)  
   - 终止条件: i >= n (i 超过最大行号) || j < 0 (j 小于最小列号)  

遍历顺序确认后，如何确定每次遍历的开始坐标？我们以左下到右上的对角线遍历为例:  
例如，现在是第2条对角线遍历(k = 2), 分为两种情况:
- k < m(最大行号)  
  显然，我们直接取开始坐标为(k, 0)即可  
- k >= m  
  这个时候，因为k已经超过了行号，我们需要将开始坐标从(m-1, 0) 往右移动 k - (m - 1)个单位， 所以现在的开始坐标为:  
  (m-1, k - m + 1)。例如：在下面的矩阵中，若k = 4: 我们的开始坐标就是(3, 1) 即14所在的位置。
  ```
  1  2  3  4
  5  6  7  8
  9  10 11 12
  13 14 15 16
  ```

## 代码

```java
public class Q0498_Diagonal_Traverse {
    public int[] findDiagonalOrder(int[][] matrix) {
        int m = matrix.length;
        if(m == 0) return new int[0];
        int n = matrix[0].length;
        int[] ans = new int[m * n];
        int idx = 0;
        for (int k = 0; k < m + n - 1; k++) {
            //up表示从左下到右上
            boolean up = (k & 1) == 0;
            //确认第k个对角线开始的坐标
            int i = up ? (k < m ? k : m - 1) : (k < n ? 0 : k - n + 1);
            int j = up ? (k < m ? 0 : k - m + 1) : (k < n ? k : n - 1);
            if(up){
                while(i >= 0 && j < n){
                    ans[idx++] = matrix[i--][j++];
                }
            }
            else{
                while(i < m && j >= 0){
                    ans[idx++] = matrix[i++][j--];
                }
            }
        }
        return ans;
    }
}
```