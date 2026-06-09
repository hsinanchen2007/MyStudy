### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        int max=0;
        int m = 0;
        int len = height.length;
        int l = 0;
        int r = len-1;
        while(l<r){
            if(height[l]<height[r]){
                 m = (r-l)*height[l];
                l++;
            }
            else{
                 m = (r-l)*height[r];
                r--;
            }
            max = Math.max(m,max);   
        }
        return max;
    }
}
```