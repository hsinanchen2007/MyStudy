### 解题思路
首先，理解题意。
盛多少水——求面积，数组中两个数的下标相减与两个数中的较小数相乘

- 解法1——暴力解法，两次遍历
当前可以盛多少水与最大容量比较，取大数，最后返回

```java
class Solution {
    public int maxArea(int[] height) {
        //暴力，两次循环遍历  
        int Area = 0;
        int len = height.length;
        for(int i = 0;i < len;i ++){
            for(int j = i+1; j < len ;j++){
                int currArea = Math.min(height[i],height[j])*(j-i);
                Area = (currArea > Area)? currArea : Area;
            }
        }
        return Area;
    }
}
```   
- 解法2——双指针
左指针指向数组的头，右指针指向数组的尾，两个指针同时移动。
那么该如何移动呢？
题目要求找到最大容器（面积），数组中的数表示高，数组下标之差表示底。
指针移动一定会导致底减少，但是移动指针也可能令高增加，所以指针移动可能会使面积增大。因此，移动当前高较小的指针，可能找到最大面积。
还是记录当前面积和当前最大面积进行比较，取大数，最后返回
### 代码

```java
class Solution {
    public int maxArea(int[] height) { 
        //双指针
        int left = 0;
        int right = height.length - 1;
        int maxArea = 0;
        while(left < right){
            maxArea = Math.max(maxArea, Math.min(height[left],height[right]) * (right - left));
            if(height[left] < height[right])
                left ++;
            else
                right--;
        }
        return maxArea;
    }
}
```