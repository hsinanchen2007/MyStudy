### 解题思路
用二重循环遍历所有的区间，遍历过程中随下标更新区间内的最小高度，更新最大面积的值。

### 代码

```java
class Solution {
    public int largestRectangleArea(int[] heights) {
        if (heights == null || heights.length == 0) {
            return 0;
        }
        int minHeight = heights[0], maxArea = 0;
        for (int from = 0; from < heights.length; from ++) {
            minHeight = heights[from];
            for (int to = from; to < heights.length; to ++) {
                minHeight = Math.min(minHeight, heights[to]);
                maxArea = Math.max(maxArea, (to - from + 1) * minHeight);
            }
        }
        return maxArea;
    }
}
```