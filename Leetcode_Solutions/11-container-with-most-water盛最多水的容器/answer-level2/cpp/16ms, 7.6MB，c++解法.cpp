### 解题思路
这道题的关键在于理解题目本质，当成底面积乘以高 ，求最大面积
两端指针向中间移动，每次选较小的值移动

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
          int max_area(0);
        int area(0);
        //指针从两端向中间移动，取delt正增益大，负增益小的
        int l(0),r(height.size()-1);
        while(l < r){
            area = min(height[l], height[r])*(r-l);
            if(area > max_area){
                max_area = area;
            }
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return max_area;
    }
};
```