### 解题思路

对于任意一个位置，所能接的最大水柱高度是包含该位置区间的左右最大值中的较小值。
从左向右看，用temp储存下一个位置的最大值，即左边的最大值；
从右向左看，同理，储存右边的最大值；
为了提高效率，在知道右边最大值后，就可以比较该位置的较小值和原高度的关系了；
这时，用sum记录和就行了。

### 代码

```java
class Solution {
    public int trap(int[] height) {
        if(height.length == 0 || height == null) return 0;
        int len = height.length;
        int[] min = new int[len];

        int temp = height[0];
        for(int i = 1; i < len-1; i++){
            min[i] = temp;
            temp = Math.max(temp, height[i]);
        }

        int sum = 0;
        temp = height[len-1];
        for(int j = len-2; j > 0; j--){
            min[j] = Math.min(temp, min[j]);
            if(min[j] > height[j]) sum += min[j]-height[j];
            temp = Math.max(height[j],temp);
        }
        return sum;
    }
}
```