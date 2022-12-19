### 解题思路
1. 暴力枚举所有的情况

时间复杂度为O(n^2)

需要注意的是i，j的取值范围，避免重复枚举

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        int max = 0;
        for(int i = 0; i < height.length - 1; i++){ 
            for(int j = i + 1; j < height.length; j++){
                int area = (j - i)*Math.min(height[i],height[j]);
                max = Math.max(max,area);
            }
        }
        return max;
    }
}
```