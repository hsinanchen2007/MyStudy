### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int largestRectangleArea(int[] heights) {
        return divideConquer(heights, 0, heights.length - 1);
    }

    public int divideConquer(int[] heights, int start, int end) {
        if (start <= end) {
            int maxArea = 0;
            int lowestHeight = Integer.MAX_VALUE;
            int lowestIndex = 0;
            for (int i = start; i <= end; i++) {
                lowestHeight = Math.min(lowestHeight, heights[i]);
            }
            for (int i = start; i <= end; i++) {
                if (lowestHeight == heights[i]) {
                    lowestIndex = i;
                    break;
                }
            }
            maxArea = (end - start + 1) * lowestHeight;
            int leftArea = divideConquer(heights, start, lowestIndex - 1);
            int rightArea = divideConquer(heights, lowestIndex + 1, end);
            return Math.max(Math.max(maxArea, leftArea), rightArea);
        } else {
            return 0;
        }
    }

}
```