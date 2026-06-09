### 解题思路
想明白原理其实很简单：
用两个指针分别放在数组头和尾，移动指针计算面积，相同长度情况面积的瓶颈在较矮的元素，减少更高的数的索引只会使面积更小（因为只是减少了长度，高度不变）。

### 代码

```java
class Solution {
        public int maxArea(int[] height) {
            int maxArea = 0;
            int n = height.length;
            assert n > 1;
            //双指针
            int i = 0, j = n - 1;
            while (i < j) {
                int tall = 0;
                int width = j - i;
                if (height[i] > height[j]) {
                    tall = height[j--];
                } else {
                    tall = height[i++];
                }
                maxArea = width * tall > maxArea ? width * tall : maxArea;
            }
            return maxArea;
        }
    }
```