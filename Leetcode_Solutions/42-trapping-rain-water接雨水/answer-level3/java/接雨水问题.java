### 解题思路
此处撰写解题思路

数组左右两个指针L 和 R，及两个变量维护[0, L]左边最大LeftMax 和[R, arr.length-1]右边最大RightMax

### 代码

```java
class Solution {
    public int trap(int[] height) {
        if (height == null || height.length < 3) {
            return 0;
        }
        int leftMax = height[0];
        int rightMax = height[height.length - 1];
        int l = 1;
        int r = height.length - 2;
        int res = 0;
        while(l <= r) {
            if (leftMax < rightMax) {
                res += Math.max(leftMax - height[l], 0);
                leftMax = Math.max(leftMax, height[l++]);
            } else {
                res += Math.max(rightMax - height[r], 0);
                rightMax = Math.max(rightMax, height[r--]);
            }
        }
        return res;
    }
}
```