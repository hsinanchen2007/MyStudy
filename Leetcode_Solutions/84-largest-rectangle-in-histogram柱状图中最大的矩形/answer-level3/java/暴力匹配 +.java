### 解题思路
优化空间很大 
但是我只会暴力匹配

### 代码

```java
import java.lang.Math;
class Solution {
    public int largestRectangleArea(int[] heights) {
        //暴力法
        int len = heights.length;

        if (len < 1) {
            return 0;
        }

        int maxSum = heights[0];

        //暴力匹配
        for (int i = 0; i < len; i++) {
            //记录最小的边
            int edge = heights[i];
            for (int j = i; j < len; j++) {
                if (heights[j] < edge) {
                    edge = heights[j];
                }
                maxSum = Math.max(maxSum, (j - i + 1)*edge);
            }
        }

        return maxSum;
    }
}
```