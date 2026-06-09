
## 思路:

可以转化和[84. 柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)一样,[题解链接](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/zhao-liang-bian-di-yi-ge-xiao-yu-ta-de-zhi-by-powc).如下图所示:


![1559999358103.png](https://pic.leetcode-cn.com/d90aa7a26a3ddaf9e77874d1d15fd4921d442cffc26663893d17c3e4503aa1a0-1559999358103.png)

就是找上图最大的矩形.

思路一:栈

我们只要遍历每行的高度,用上一题方法(栈)求出最大矩形!

思路二:动态规划

用`height_j`记录第`i`行为底,第`j`列高度是多少.

用`left_j`记录第`i`行为底, 第`j`列左边第一个小于`height_j[j]`的位置

用`right_j`记录第`i`行为底, 第`j`列右边第一个小于`height_j[j]`的位置



## 代码:

思路一:

```python [1]
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix or not matrix[0]: return 0
        row = len(matrix)
        col = len(matrix[0])
        height = [0] * (col + 2)
        res = 0
        for i in range(row):
            stack = []
            for j in range(col + 2):
                if 1<=j<=col: 
                    if matrix[i][j-1] == "1":
                        height[j] += 1
                    else:
                        height[j] = 0
                while stack and height[stack[-1]] > height[j]:
                    cur = stack.pop()
                    res = max(res, (j - stack[-1] - 1)* height[cur])
                stack.append(j)
        return res
```



```java [1]
class Solution {
    public int maximalRectangle(char[][] matrix) {
        if (matrix == null || matrix.length == 0) return 0;
        int row = matrix.length;
        int col = matrix[0].length;
        int[] height = new int[col + 2];
        int res = 0;
        for (int i = 0; i < row; i++) {
            Deque<Integer> stack = new ArrayDeque<>();
            for (int j = 0; j < col + 2; j++) {
                if (j >= 1 && j <= col) {
                    if (matrix[i][j-1] == '1') height[j] += 1;
                    else height[j] = 0;
                }
                while (!stack.isEmpty() && height[stack.peek()] > height[j]) {
                    int cur = stack.pop();
                    res = Math.max(res, (j - stack.peek() - 1) * height[cur]);
                }
                stack.push(j);
            }
        }
        return res;  
    }
}
```

思路二:

```python [2]
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix or not matrix[0]: return 0
        row = len(matrix)
        col = len(matrix[0])
        left_j = [-1] * col
        right_j = [col] * col
        height_j = [0] * col
        res = 0
        for i in range(row):
            cur_left = -1
            cur_right = col

            for j in range(col):
                if matrix[i][j] == "1":
                    height_j[j] += 1
                else:
                    height_j[j] = 0

            for j in range(col):
                if matrix[i][j] == "1":
                    left_j[j] = max(left_j[j], cur_left)
                else:
                    left_j[j] = -1
                    cur_left = j

            for j in range(col - 1, -1, -1):
                if matrix[i][j] == "1":
                    right_j[j] = min(right_j[j], cur_right)
                else:
                    right_j[j] = col
                    cur_right = j
            for j in range(col):
                res = max(res, (right_j[j] - left_j[j] - 1) * height_j[j])
        return res
        
```



```java [2]
class Solution {
    public int maximalRectangle(char[][] matrix) {
        if (matrix == null || matrix.length == 0) return 0;
        int row = matrix.length;
        int col = matrix[0].length;
        int[] left_j = new int[col];
        Arrays.fill(left_j, -1);
        int[] right_j = new int[col];
        Arrays.fill(right_j, col);
        int[] height_j = new int[col];
        int res = 0;
        for (int i = 0; i < row; i++) {
            int cur_left = -1;
            int cur_right = col;
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1') height_j[j] += 1;
                else height_j[j] = 0;
            }
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1') left_j[j] = Math.max(left_j[j], cur_left);
                else {
                    left_j[j] = -1;
                    cur_left = j;
                }
            }
            for (int j = col - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') right_j[j] = Math.min(right_j[j], cur_right);
                else {
                    right_j[j] = col;
                    cur_right = j;
                }
            }
            for (int j = 0; j < col; j++) res = Math.max(res, (right_j[j] - left_j[j] - 1) * height_j[j]);

        }
        return res;  
    }
}
```

