### 解题思路
参考评论中解法，从两端分别向中间靠拢，每次移动距离均为1，容器最低高度由低边决定，则哪边低哪边向内移动，知道相遇，搜索到最大值。

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int left = 0;
        int right = len - 1;
        int area = 0;
        while(left < right){
            area = max(area, min(height[right], height[left])*(right-left));
            if(height[right]>height[left]) left++;
            else right--;
        }
        return area;
    }
};
```