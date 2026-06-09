### 解题思路
rt

### 代码

```java
class Solution {
    public int trap(int[] height) {
        int maxHeight = 0;
        int sumHeight = 0;
        for (int i = 0; i < height.length; i++) {
            sumHeight += height[i];
            if (height[i] > maxHeight){
                maxHeight = height[i];
            }
        }
        int totalS = 0; //围起来的总面积
        for (int i = 1; i <= maxHeight; i++) {
            int firstIndex = 0;
            int lastIndex = 0;
            for (int j = 0; j < height.length; j++) {
                if (height[j] >= i){
                    firstIndex = j;
                    break;
                }
            }
            for (int j = height.length-1; j >= 0; j--) {
                if (height[j] >= i){
                    lastIndex = j;
                    break;
                }
            }
            totalS += (lastIndex - firstIndex +1) ;
        }
        return totalS - sumHeight;
    }
}
```