### 解题思路
根据木桶效应，最大面积取决于较短边的长度和两边距离的乘积，在这个问题中起初从数组两端开始
每次比较与之前的最大值的大小，并且找到较小的边，如果是左边就向后移，右边就向前移动。

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        int i = 0;
        int j = height.length-1;
        int max = 0;
        while(i<j) {
            int min = Math.min(height[i], height[j]);
            max = Math.max(max,min*(j-i));
            if(height[i] < height[j]) {
                i++;
            }else {
                j--;
            }
        }

        return max;
    }
}
```