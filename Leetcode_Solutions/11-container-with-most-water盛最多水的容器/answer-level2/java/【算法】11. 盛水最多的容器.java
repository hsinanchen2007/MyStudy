### 解题思路
水桶装水的容量，取决于最短的一边。所以，可得面积计算公式为 `(right - left) * Math.min(height[left], height[right]);` 想要面积最大，要么 (right -left)较大，要么(Math.min(height[left],height[right]))更大。
先从(right - left)着手，使用两个指针分别从两边向内遍历，不管怎么样遍历，(right - left)一定是越来越小的。

所以就需要更大的高度，比较两个木板的高度，把较小一边的指针向内移动，求出最大值即可。


### 代码

```java
class Solution {
    public int maxArea(int[] height) {
         int max = 0;
         int left = 0;
         int right = height.length - 1;

         while(left<right){
             int capacity = (right - left) * Math.min(height[left], height[right]);
             max = Math.max(max, capacity);
             if(height[left] < height[right]){
                 left ++;
             }else if(height[left] > height[right]){
                 right--;
             }else{
                 left++;
                 right--;
             }
         }
         return max;
    }
}
```