### 题目

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

 
[无效的图片地址](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg)


The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

### 解题思路

设置left = 0;right=height.length-1;

1. 初始容量(right-left)*Math.min(height[left],height[right]); 

2. 注意到容量计算是min*width：
    - 如果此时[left] > [right] 说明：left柱子高,right柱子矮。
    
        - 如果left向右移动，无论[left+1]的高度是什么样子的，[left+1]~[right]的容量一定是小于[left]~[right]的容量的。(因为基准高度不会大于[right],而距离在缩小)。依次推下去[left+x]~[right]的容量也是小于[left]~[right]的容量的。所以这种情况下left右移没有意义，只有right左移才可能出现比当前容量大的情况；
                
    - 如果此时[left] < [right] 说明：left柱子矮,right柱子高。
        - 同样，因为现在基准高度是[left], [left]~[right-1]或者[left]~[right-x]的值一定小于[left]~[right]。所以这种情况下要将left右移才可能出现比当前容量的情况。
                
    - 如果此时[left] = [right] 说明：一样高
        
        - 继续向上边一样思考，会发现left右移，right不变，基准高度不会超过[right]，容量只会变小。right左移，left不变，基准高度不会超过[left],容量也只会变小。 只有同时移动left和right才可能出现大于当前容量的情况。
                
    

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
       int left = 0;
       int right = height.length - 1;
       int max = 0;
       while(left < right) {
            int thisMax = (right - left) * Math.min(height[left],height[right]);
            max = Math.max(thisMax,max);
            if(height[left] < height[right]) {
                left++;
            } else if(height[left] > height[right]) {
                right--;
            } else {
                left++;
                right--;
            }
       } 
       return max;
    }
}
```