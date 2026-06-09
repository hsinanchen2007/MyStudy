### 解题思路
头尾指针，面积由较小值来确定，计算完成后，小的指针向中间移动
### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        int max = 0, i = 0, j = height.length - 1;
        while (i < j) {
            max = Math.max((j - i) * Math.min(height[i], height[j]), max);
            if (height[i] <= height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return max;
    }
}
```