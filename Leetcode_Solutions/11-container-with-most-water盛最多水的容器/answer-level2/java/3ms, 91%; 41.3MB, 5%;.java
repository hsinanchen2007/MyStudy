### 解题思路
使用双指针法，一个在头，一个在尾，使用循环结构，每一次计算容器的面积，然后比对两边的高度，高度矮的一方往后（或前）移动，直到其高度上升为止，再重新开始新一轮循环。

### 代码

```java
class Solution {
    public static int maxArea(int[] height) {
        // 基本的情况是 height 长度 < 2
        if(height.length <= 1)
            return 0;
        // 双指针 i, j
        int i = 0, j = height.length - 1;
        int area = Integer.MIN_VALUE;

        // 只要 i 还比 j 小, 就可以继续计算面积
        while(i < j){
            int newArea = (j - i) * Math.min(height[i], height[j]);
            if(area < newArea){
                area = newArea;
            }
            int k;
            // 如果 height[i] 的值不大于 height[j] 的值，就往后移动到第一个高度大于 height[i] 的点
            if(height[i] <= height[j]){
                for(k = i + 1; k < j && height[k] <= height[i]; k++);
                i = k;
                continue;
            }

            // 当 height[j] < height[i] 时, 同理
            if(height[i] > height[j]){
                for(k = j - 1; k > i && height[k] <= height[j]; k--);
                j = k;
            }
        }
        return area;
    }
}
```