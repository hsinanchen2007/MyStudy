### 解题思路
暴力方法解决这些问题，时间复杂度是O(N^2) 龙剑复杂度为O(1)
1.寻找两两之间的柱子，找出两两对应的柱子之间高度的最小值，min
2.找到的两个柱子之间的最大矩形面积是两个柱子之间min值和两个柱子坐标之间的差值的乘积 （j-i+1）*min
3.依次遍历所有可能出现的两两柱子之间的矩形面积，计算出最大的矩形面积

### 代码

```java
class Solution {
    public int largestRectangleArea(int[] heights) {
        int res = 0;
        for(int i = 0; i< heights.length;i++){
            int min = Integer.MAX_VALUE;
            for(int j = i;j<heights.length;j++){
                min = Math.min(min,heights[j]);
                res = Math.max(res, min*(j-i+1));
            }
        }
        return res;
        
    }
}
```