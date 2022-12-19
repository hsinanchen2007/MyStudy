### 解题思路
最普通的解题方法是抓住一点，存水靠左右柱最低的那一根，所以基本思路是遍历所有的横坐标，遍历的每一步都要找当前步中最大高度的左右柱子，并取较小的那一个做为存水的临界值，然后累加。
但是这样的话时间复杂度比较高，所以需要进行优化，由于此处出现了左右柱，所以能联想到双指针，如何在遍历每一横坐标的时候只靠双指针就能完成当前步的存水计算，这就要通过定义左右柱子当前步最大高度，
然后用左右双指针实时更新这个最大值来实现，并且注意到当前横坐标的存水还是受到左右最大柱的高度较小值决定的，而且不会受到高度较大值的任何影响，所以就有了下述代码

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())
            return 0;
        int ans = 0;
        int p_left_max = 0;
        int p_right_max = height.size()-1;
        int p_left = 0;
        int p_right = height.size()-1;
        while(p_left<=p_right){
            if(height[p_left]<height[p_right]){
                if(height[p_left]<height[p_left_max]){
                    ans +=height[p_left_max] - height[p_left];
                }
                else{
                    p_left_max = p_left;
                }
                p_left++;
            }
            else{
                if(height[p_right]<height[p_right_max]){
                    ans += height[p_right_max]-height[p_right];
                }
                else{
                    p_right_max = p_right;
                }
                p_right--;
            }
        }
        return ans;
    }
};
```