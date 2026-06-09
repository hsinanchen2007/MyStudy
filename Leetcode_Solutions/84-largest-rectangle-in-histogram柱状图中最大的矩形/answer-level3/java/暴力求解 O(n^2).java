### 解题思路


### 代码

```java
class Solution {
    public int largestRectangleArea(int[] heights) {
        int max = 0;
        for (int i = 0; i < heights.length; i ++) {
            int minH = Integer.MAX_VALUE;
            for (int j = i; j < heights.length; j ++ ) {
                minH = Math.min(minH,heights[j]);
                max = Math.max(max, (minH * (j - i + 1)));
            }
        }
        return max;
    }
}
```