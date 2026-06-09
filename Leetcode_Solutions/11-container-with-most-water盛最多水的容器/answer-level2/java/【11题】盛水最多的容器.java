**题目分析**
(1) 计算两条垂直线和 x 轴组成容器的容量，主要依赖两垂直线距离和较短垂直线的高度。
(2) 相当于计算一个宽为两垂直线的距离高为较短垂直线高度的矩形面积。
*** 相关理论：木桶效应。

**方法一：暴力**
思路：
(1) 双层循环遍历所有组成的矩形面积，每次记录最大面积。
(2) 遍历完成返回最大面积。
```
class Solution {
    public int maxArea(int[] height) {
        int ans = 0;
        int len = height.length;
        if (len < 2){
            return 0;
        }
        // 外层循环遍历第一条线，内层循环遍历第二条线。
        for (int i = 0; i < len - 1; i++){
            for (int j = i + 1; j < len; j++){
                // 比较记录的最大面积和当前组成的面积，将较大的记录。
                ans = Math.max(ans, (j - i) * Math.min(height[i],height[j]));
            }
        }
        return ans;
    }
}
```

**方法二：双指针**
思路：
(1) 定义两个指针从数组两边开始遍历组成的矩形，并记录面积。
(2) 左右垂直线哪边比较低，哪边就向中间移动指针，然后计算组成的矩形面积并记录较大值。
(3) 直到左右指针指向同一条垂直线则遍历完成，返回记录的最大面积。
```
class Solution {
    public int maxArea(int[] height) {
        int ans = 0;
        int len = height.length;
        if (len < 2){
            return 0;
        }
        int left = 0, right = len - 1;
        while(left < right){
            // 矩形的宽。
            int h = right - left;
            // 矩形的高。
            int v = height[right] < height[left] ? height[right--] : height[left++];
            ans = Math.max(ans, h * v);
        }
        return ans;
    }
}
```
