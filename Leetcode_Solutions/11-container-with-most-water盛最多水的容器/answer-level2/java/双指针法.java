### 解题思路
双指针法，因为这个题目中面积大小只和两端的柱子高度相关，不用考虑中间的柱子，所以只要考虑移动两边柱子，因为这里考虑的是短板，所以当距离缩小时，移动短板才可能遇到高板，因为距离缩短只有遇到高板才能让面积变大。双指针法是从数组的两边开始，可以看成是暴力解法的子集。

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        //暴力解法 ： 穷举法计算面积取最大值
    //     int maxArea = 0;
    //     for (int i = 0; i < height.length; i++) {
    //         for (int j = i; j < height.length; j++) {
    //         maxArea = Math.max(Math.min(height[i], height[j]) * Math.abs(i - j), maxArea);           }    
    // }
    // return maxArea;

        //双指针法
            int maxArea = 0;
        int start = 0;
        int end = height.length - 1;
         while (start < end) {
        maxArea = Math.max(Math.min(height[start], height[end]) * (end - start), maxArea);
            if (height[start] > height[end]) {
                end--;
            } else {
                start++;
            }
        }
        return maxArea;
    }
}
```