### 解题思路
双指针法，两个指针移动，每次指针移动都计算一次两个指针的面积，移动有顺序，
1、当左边指针所在的数字小于右边数组所在数字时，向左移动，也就是：l++;
2、右边小，则右指针移动，r-- ；
3、计算面积按照（r-l）* 两个指针所在数字的最小值


### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        int l =0;
        int r = height.length -1;
        int maxArea = 0;
        while (l<r) {
            int len = height[r] > height[l] ? height[l] : height[r];
            int arer = (r-l) * len;
            if (maxArea < arer) {
                maxArea = arer;
            }

            if (height[r] > height[l]) {
                l ++;
            } else {
                r--;
            }
        }
        return maxArea;
    }
}
```