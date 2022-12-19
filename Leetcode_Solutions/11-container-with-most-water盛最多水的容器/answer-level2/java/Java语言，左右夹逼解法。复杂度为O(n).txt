### 解题思路
第一种是暴力解法，即是通过两层循环遍历所有的可能性，求出其中的最大值。
需要注意的是i<length-1这个地方。
第二种解法：
1、左右夹逼的解法，从左右两个方向向中间夹逼，宽度最大的情况下，每次将高度短的柱子换掉
可以简单理解为：在宽度不断变小的情况下，如果高度不升高则不会存在更大的面积。

### 代码
```java
解法一：
class Solution {
    public int maxArea(int[] height) {
        int max = 0;
        for(int i=0;i<height.length-1;i++) {
            for(int j = i+1;j<height.length;j++) {
                int minHeight = Math.min(height[i],height[j]);
                max = Math.max(max,(j - i)*minHeight); 
            }
        }
        return max;

    }
}

解法二：
class Solution {
    public int maxArea(int[] height) {
        int max = 0;
        for(int i = 0,j = height.length-1;i < j;){
            int minHeight = (height[i] < height[j]) ? height[i++] : height[j--];
            max = Math.max(max,(j-i+1)*minHeight);
        }
        return max;
    }
}
```