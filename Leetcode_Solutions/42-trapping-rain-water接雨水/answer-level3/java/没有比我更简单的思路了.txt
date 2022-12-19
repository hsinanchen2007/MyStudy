### 解题思路
任意位置i处，能承接雨水的数量=min(左边最高的柱子高度,右边最高的柱子高度)-i处的高度。
所以分别拿两个数组存i处左边最大值和右边最大值就好了

### 代码

```java
class Solution {

    public int trap(int[] heights) {
        if (heights.length < 3) {
            return 0;
        }
        int result = 0;
        int[] left = new int[heights.length];
        int[] right = new int[heights.length];
        int max = 0;
        for (int i = 0; i < heights.length; i++) {
            if (heights[i] > max) {
                max = heights[i];
            }
            left[i] = max;
        }
        max = 0;
        for (int i = heights.length - 1; i >= 0; i--) {
            if (heights[i] > max) {
                max = heights[i];
            }
            right[i] = max;
        }
        for (int i = 0; i < heights.length; i++) {
            result += Math.max(Math.min(left[i], right[i]) - heights[i], 0);
        }
        return result;
    }
}
```