### 解题思路
1. 定义i,j分别指向数组的第一个元素与最后一个元素位置
2. 每次比较i，j两个位置线的高度，计算面积，并与最大值进行比较，取较大值保存
3. 保留较高的位置点，舍弃较低点，并向中间移动（该方法能够保证在向中间移动的过程中面积的最优选择）

### 时间复杂度
该方法只需要遍历一遍元素，所以时间复杂度为O(n)

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        int max = 0;
        for (int i = 0,j = height.length - 1; i < j;){
            int area = (j - i) * (height[i] < height[j] ? height[i++] : height[j--]);
            max = Math.max(max,area);
        }

        return max;
    }
}
```