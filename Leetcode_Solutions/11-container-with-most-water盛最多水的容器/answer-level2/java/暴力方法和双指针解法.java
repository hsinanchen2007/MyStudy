### 解题思路
1.暴力方法
- 双重循环，判断每一个的大小
- max = Math.max(max,(j-i)*Math.min(height[i],height[j]));
2.双指针
- 设置左右两端的指针进行处理，并统计每次的最大值。这样可以一次遍历完成，时间复杂度O(N)
- 当l或者r其中一个较小时，l++ 或者 r++.因为宽度的改变没有高度的改变造成的影响大。

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        int max = 0;
        int l = 0;
        int r = height.length-1;
        while(l < r){
            max = Math.max(max,(r-l)*Math.min(height[l],height[r]));
            if(height[l] < height[r]){
                l++;
            }else{
                r--;
            }
        }
    
        return max;
    }
}
```