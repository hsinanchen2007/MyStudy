## 思路:

与上一题 [54. 螺旋矩阵](https://leetcode-cn.com/problems/spiral-matrix/)一样,[题解链接](https://leetcode-cn.com/problems/spiral-matrix/solution/mo-ni-guo-cheng-by-powcai-2)

还是模拟过程,控制好边界

行的上下边界, 列的左右边界!即可

时间复杂度: $O(n^2)$



## 代码:



```python [1]
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        above_row = 0
        below_row = n - 1
        left_col = 0
        right_col = n - 1
        res = [ [0] * n for _ in range(n) ]
        num = 1
        while above_row <= below_row and left_col <= right_col:
            # 从左到右
            for i in range(left_col, right_col+1):
                res[above_row][i] = num
                num += 1
            # 上行加1
            above_row += 1
            # 从上到下
            for i in range(above_row, below_row+1):
                res[i][right_col] = num
                num += 1
            right_col -= 1
            # 从右到左
            for i in range(right_col, left_col-1, -1):
                res[below_row][i] = num
                num += 1
            below_row -= 1
            #从下到上
            for i in range(below_row, above_row-1, -1):
                res[i][left_col] = num
                num += 1
            left_col += 1
        return res
```



```java [1]
class Solution {
    public int[][] generateMatrix(int n) {
        int[][] res = new int[n][n];
        int above_row = 0;
        int below_row = n - 1;
        int left_col = 0;
        int right_col = n - 1;
        int num = 1;
        while (above_row <= below_row && left_col <= right_col) {
            // 从左到右
            for (int i = left_col; i <= right_col; i++) {
                res[above_row][i] = num;
                num++;
            }
            above_row++;
            // 从上到下
            for (int i = above_row; i <= below_row; i++) {
                res[i][right_col] = num;
                num++;
            }
            right_col--;
            // 从右到左
            for (int i = right_col; i >= left_col; i--) {
                res[below_row][i] = num;
                num++;
            }
            below_row--;
            // 从下到上
            for (int i = below_row; i >= above_row; i--) {
                res[i][left_col] = num;
                num++;
            }
            left_col++;
        }
        return res;  
    }
}
```

