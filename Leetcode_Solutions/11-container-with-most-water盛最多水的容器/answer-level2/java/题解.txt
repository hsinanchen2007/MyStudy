### 解题思路
双指针优化的暴力法

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        if (height.length == 0) return 0;
        int max = 0;
        for (int i = 0; i < height.length - 1; i++) {
            for (int j = i + 1; j < height.length; j++) {
                int temp = (j - i) * Math.min(height[i], height[j]);
                max = max < temp ? temp : max;
            }
        }
        return max;
    }
}
```