### 解题思路
双指针解法

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        // 双指针做法,同样还是找两边比自身高的柱子，然后计算自身接雨水的量
        int ans = 0;
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        while (left < right) {
            // 这里的判断条件必须是height[left] < height[right],这样可以保证到最后重合的点是最高点
            // 如果使用left_max < right_max，则不能保证，如果非要用这个判断条件，可以把while的判断条件改成left <= right也行，用于保证每个位置的接水量都被计算进来
            if (height[left] < height[right]) {
                height[left] >= left_max ? left_max = height[left] : ans += left_max - height[left];
                left++;
            } else {
                height[right] >= right_max ? right_max = height[right] : ans += right_max - height[right];
                right--;
            }
        }

        return ans;
    }
};
```