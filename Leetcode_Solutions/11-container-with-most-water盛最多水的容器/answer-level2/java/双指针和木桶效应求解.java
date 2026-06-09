### 解题思路
木桶效应，让最短的木板尽可能的变长

执行用时 :4 ms, 在所有 Java 提交中击败了74.82%的用户

### 代码

```java
class Solution {
 public static int maxArea(int[] height) {
        int i = 0, j = height.length - 1;
        int maxArea = 0;
        while (i < j) {
            int currentArea = Math.min(height[i], height[j]) * (j - i);
            maxArea = Math.max(currentArea, maxArea);

            //木桶效应，让最短的木板尽可能的变长
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return maxArea;
    }
}
```