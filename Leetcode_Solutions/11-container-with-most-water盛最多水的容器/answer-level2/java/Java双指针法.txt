### 解题思路
容器的面积是由长度和高度决定的，高度是取决于容器左边和右边最短的那部分，而长度是最左边和最右边的距离。所以我们从数组两边开始，首先判断容器的最左边和最右边的高度哪边更高，我们自然是更希望留下更高的那段，那就只能让短的那边往另一端更高的地方移动，直到容器两边的距离不大于1为止。

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        int ans = 0;
        int l = 0;
        int r = height.length - 1;
        while (l < r){
            ans = Math.max(Math.min(height[l], height[r]) * (r - l), ans);
            if (height[l] < height[r]){
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
}
```