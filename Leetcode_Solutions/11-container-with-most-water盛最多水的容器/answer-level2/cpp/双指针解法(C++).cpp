### 解题思路
我们知道两线段之间围成的区域面积受其中较小的线段长度的限制，所以，利用left和right双指针，向较短的线段移动，并更新所围区域面积
step1：设定数组左右指针left、right并初始化left=0，right=height.size()-1
step2：更新区域面积，即MaxArea=max(MaxArea, area)
step3：引导指针向较短的线段移动，即left++或者right--

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int MaxArea = 0, left = 0;
        int right = height.size() - 1;
        while(left < right)
        {
            int area = min(height[left], height[right]) * (right - left);
            MaxArea = max(MaxArea, area);
            if(height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return MaxArea;
    }
};
```