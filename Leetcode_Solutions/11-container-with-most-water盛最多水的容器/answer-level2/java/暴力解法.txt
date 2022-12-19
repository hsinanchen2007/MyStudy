### 解题思路
暴力解法，用一个大小递减窗口遍历所有面积，取最大;

### 代码

```java
class Solution {
    public static int maxArea(int[] height) {
        int maxA = 0;
        int length = height.length;
        int leftHigh,rightHigh,high;
        // 长度为i
        for (int i = length;i>0;i--){
            // 当前遍历起始下标为j
            for (int j = 0;j <= length -i; j++){
                leftHigh = height[j];
                rightHigh = height[j+i-1];
                high = Math.min(leftHigh,rightHigh);
                maxA = high*(i-1) > maxA ? high*(i-1):maxA;
            }
        }
        return maxA;
    }
}
```