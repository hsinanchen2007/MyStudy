### 解题思路
left, right为待扫描索引范围，leftMax为left左边元素的最大值，rightMax为right右边元素的最大值

### 代码

```java
class Solution {
    public int trap(int[] height) {
        int len = height.length;
        if (len == 0) return 0;
        int left = 1, right = len - 2;
        int leftMax = height[0], rightMax = height[len-1];
        int result = 0;
        while (left <= right) {
            if (leftMax < rightMax) {
                if (height[left] >= leftMax)
                    leftMax = height[left];
                else
                    result += leftMax - height[left];
                left++;
            } else {
                if (height[right] >= rightMax)
                    rightMax = height[right];
                else
                    result += rightMax - height[right];
                right--;
            }
        }
        return result;
    }
}
```