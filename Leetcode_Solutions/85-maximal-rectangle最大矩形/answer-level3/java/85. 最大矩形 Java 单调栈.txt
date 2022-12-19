### 单调栈

做 n 次 [84. 柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/). 

以每一行作为底, 统计矩形高度, 代入 84 题的算法计算. 时间复杂度 $o(nm)$

### 代码

```java
class Solution {
    private int largestRectangleArea(int[] heights) {
        Stack<Integer> stk = new Stack<>();
        int res = 0;
        for (int i = 0; i < heights.length; i++) {
            while (!stk.isEmpty() && heights[i] < heights[stk.peek()]) {
                int idx = stk.pop();    // 计算 idx 的柱子往左右延伸能得到的最大矩形面积
                int h = heights[idx];
                int w = i - (stk.isEmpty() ? 0 : stk.peek() + 1);
                res = Math.max(res, h * w);
            }
            stk.push(i);
        }
        // 把栈中剩余的元素一一弹出, 并计算
        while (!stk.isEmpty()) {
            int idx = stk.pop();    // 计算 idx 的柱子往左右延伸能得到的最大矩形面积
            int h = heights[idx];
            int w = heights.length - (stk.isEmpty() ? 0 : stk.peek() + 1);
            res = Math.max(res, h * w);
        }
        return res;
    }

    public int maximalRectangle(char[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return 0;
        }
        int res = 0;
        int n = matrix.length, m = matrix[0].length;
        int[] heights = new int[m];
        for (int bottom = 0; bottom < n; bottom++) {
            // 计算以 bottom 为底的 heights
            for (int i = 0; i < m; i++) {
                heights[i] = 0;
                for (int j = 0; bottom + j < n && matrix[bottom + j][i] == '1'; j++) {
                    heights[i]++;
                }
            }
            // 使用单调栈计算最大矩形
            res = Math.max(res, largestRectangleArea(heights));
        }
        return res;
    }
}
```