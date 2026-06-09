### 解题思路
yeah yeah yeah

### 代码

```java
class Solution {
    public int trap(int[] height) {
        int[] left = new int[height.length];
        int[] right = new int[height.length];
        for(int i =0; i<height.length; i++){
            left[i] = i==0?height[i]:Math.max(left[i-1], height[i]);
        }
        for(int j = height.length-1; j >= 0; j--){
            right[j] = j==height.length-1?height[j]:Math.max(right[j+1], height[j]);
        }
        int res = 0;
        for(int i =0; i<height.length; i++){
            res += Math.min(left[i], right[i]) - height[i];
        }
        return res;

    }
}
```