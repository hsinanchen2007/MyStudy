### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        if (null == height || height.length <= 1) {
            return 0;
        }

        int maxArea = 0;
        int low = 0;
        int high = height.length - 1;

        while (low < high) {
            int area = 0;
            if (height[low] < height[high]) {
                area = height[low] * (high - low);
                low++;
            } else {
                area = height[high] * (high - low);
                high--;
            }

            if (area > maxArea) {
                maxArea = area;
            }
        }

        return maxArea;
    }
}
```