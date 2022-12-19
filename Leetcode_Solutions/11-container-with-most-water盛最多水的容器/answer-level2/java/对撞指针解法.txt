### 解题思路
对撞指针，从两头找，短边为高乘底算体积，每次短边偏移高边不变。

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        int l = 0;
        int r = height.length - 1;
        int max = 0;
        while (l < r) {
            int h = height[l] > height[r]? height[r]:height[l];
            int v = h * (r - l);
            if (max < v) max = v;
            if (height[l] <= height[r]) l++;
            else r--;
        }
        return max;
    }
}
```