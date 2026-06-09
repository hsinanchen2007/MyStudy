### 解题思路
双指针法
分别指向最左和最右，当其中一方的ai（y值）小于另一方，其指针（x值）往长的那一端移动，【不断重复短的一端向长的一端移动，并且记录期间面积的最大值】。

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        if(height.length < 2) return 0;
        int left = 0;
        int right = height.length - 1;
        int res = 0;
        while(left < right){
            res = height[left] < height[right] ? 
            Math.max(res, (right - left) * height[left++]): 
            Math.max(res, (right - left) * height[right--]); 
         }
        
        
        return res;
    }
}
```