### 解题思路
使用暴力破解，对height 中的每个元素寻找其左边和右边最大

### 代码

```java
class Solution {
    public int trap(int[] height) {
        if(height.length < 3) return 0;
        int total_volume = 0;
        int left_max = 0;
        int right_max = 0;
        for(int i=1;i<height.length-1;i++){ //排除第0个和最后一个元素，因为他们的左边或者右边没有墙，不能构成V型容器
            left_max = 0;  // 每次必须重置左边右边最大值
            right_max = 0; // 每次必须重置左边右边最大值
            for(int l=0;l <= i;l++){
                left_max = left_max > height[l] ? left_max : height[l];
            }
            for(int r = i; r < height.length; r++ ){
                right_max = right_max > height[r] ? right_max : height[r];
            }

            total_volume += Math.min(left_max,right_max) - height[i];
        }
        return total_volume;
    }
}
```