### 解题思路
本题可以用最简单的算法来做，从第一个矩形往后面遍历，采用两层循环，第一层循环是大循环，用来作为“结果矩形”的首位矩形，第二层循环作为“结果矩形”的末位矩形。在第二层循环中不断更新“结果矩形”的高度。如此遍历，不断更新最大矩形面积。便可得到正确结果。

### 最后打一波公益广告：欢迎大家加入 leetcode 刷题群：QQ：940835717（升值加薪冲冲冲），互相监督学习，共同成长，欢迎志同道合之士加入。

### 代码

```java
class Solution {
    public int largestRectangleArea(int[] heights) {
        int max = 0;
        for (int i = 0; i < heights.length; i++) {
            int minHeight = heights[i];
            // 计算单个矩形
            if (max < heights[i]) {
                max = heights[i];
            }
            for (int j = i + 1; j < heights.length; j++) {
                // 计算多个矩形的组合
                if (heights[j] < minHeight) {
                    minHeight = heights[j];
                }
                int temp = minHeight * (j - i + 1);
                if (temp > max) {
                    max = temp;
                }
            }
        }
        return max;
    }
}
```