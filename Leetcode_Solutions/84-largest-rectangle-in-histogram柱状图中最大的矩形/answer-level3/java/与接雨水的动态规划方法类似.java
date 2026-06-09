### 解题思路
以height[i]为高的矩形要使面积最大，宽就要最大，当左右两边以第一个比height[i]小的值的下标为边界时，宽最大。
left[i]表示height[i]左边第一个小于height[i]的数的下标。
right[i]表示height[i]右边第一个小于height[i]的数的下标。
(right[i]-left[i]-1)为最大宽。
left[i]的取值通过判断左边第一个元素是否比height[i]小，小则达到下标，否则取第一个元素的left值继续比较。

### 代码

```java
class Solution {
   public int largestRectangleArea(int[] heights) {
        if (heights==null || heights.length<1)return 0;
        int[] left = new int[heights.length];//left[i]表示height[i]左边第一个小于height[i]的数的下标
        int[] right = new int[heights.length];//right[i]表示height[i]右边第一个小于height[i]的数的下标
        left[0] = -1;
        for (int i = 1; i < heights.length; i++) {
            int index = i-1;
            while (index!=-1 && heights[index]>=heights[i])
                index = left[index];
            left[i] = index;
        }
        right[heights.length-1] = heights.length;
        for (int i = heights.length-2; i >= 0 ; i--) {
            int index = i+1;
            while (index!=heights.length && heights[index]>=heights[i])
                index = right[index];
            right[i] = index;
        }
        int res = 0;
        for (int i = 0; i < heights.length; i++) {//以height[i]为高的矩形宽最大为(right[i]-left[i]-1)
            res = Math.max(res , heights[i]*(right[i]-left[i]-1));
        }
        return res;
    }

}
```