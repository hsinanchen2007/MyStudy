### 解题思路
    借助双指针来完成高度图的遍历:
    初始化left 指针为 0 ，right 指针为 length-1
    1、如果一端有更高的条形块（例如右侧），积水的高度依赖于当前方向的高度（从左到右遍历）,
       记录当前能达到的最高位置，接雨水数等于最大高度减去当前高度的值;
    2、如果另一侧（例如右侧）的条形块高度不是最高的，从相反的方向遍历（从右到左），
       同样记录当前能达到的最高位置，接雨水数等于最大高度减去当前高度的值;
    3、两指针相遇时结束。

### 代码

```java
class Solution {
   
    public int trap(int[] height) {

        int left = 0,right = height.length-1;
        int max_left =0, max_right = 0;
        int ans = 0;
        while(left < right){
            if(height[left] < height[right]){
                if(height[left] >= max_left){
                    max_left = height[left];
                }else{
                    ans += max_left - height[left];
                }
                ++left;
            }else{
                if(height[right] >= max_right){
                    max_right = height[right];
                }else{
                    ans += max_right - height[right];
                }
                --right;
            }
        }
        return ans;

    }
}
```