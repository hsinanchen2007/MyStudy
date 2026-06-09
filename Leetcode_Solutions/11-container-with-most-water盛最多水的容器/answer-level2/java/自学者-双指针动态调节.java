### 解题思路
* 首尾双指针动态调节首尾
* 初等数学矩形宽度 * 矩形高度 = 矩形面积
* 动态调节的原则：将指向**较短线段的指针**向**较长线段那端**移动一步。（左侧往右或者右侧往左）。

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        int maxArea = 0;
        int left = 0;
        int right = height.length - 1;
        while (left < right) {
            int rectWidth =  right - left;
            int rectHeight =  Math.min(height[left], height[right]);
            maxArea = Math.max(maxArea, rectWidth * rectHeight);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
}
```