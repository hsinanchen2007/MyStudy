
首先我们需要搞清楚，下标为i的雨水量是由什么决定的,---->是由i左右两边最大值中较小的那个减去height[i]决定的.例 [0,1,0,2,1,0,1,3,2,1,2,1]中，下标为2的位置 值为0，而它的用水量是由左边的最大值1，右边最大值3 中较小的那个 也就是1减去0得到的。
本题解的双指针先找到当前维护的左、右最大值中较小的那个，例 当前左边的最大值如果比右边的小，那么就可以不用考虑右边最大值的影响了，因为右边的最大值绝对比左边的最大值要大，在不断遍历时，更新max_l和max_r以及返回值即可。
```
class Solution {
    public int trap(int[] height) {
        int l=0;
        int r=height.length-1;
        int max_l=0;
        int max_r=0;
        int res=0;
        while(l<=r){
            if(max_l<max_r){
                if(height[l]<max_l) res+=max_l-height[l];
                else max_l=height[l];
                l++;
            }else {
                if(height[r]<max_r) res+=max_r-height[r];
                else max_r=height[r];
                r--;
            }
        }
        return res;
    }
    
}
```
