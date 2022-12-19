### 解题思路
思路类似接雨水，双指针，两头依次向中间逼近，取最大面积即可。注意因为是两端作为边，宽为右坐标-左坐标，不用+1。

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        if(n<2) return 0;
        int water=0;
        int left=0,right=n-1;
        int max_left=0,max_right=0;
        for(int i=0;i<n-1;i++)
        {
            if(height[left]<height[right])
            {
                int area=height[left]*(right-left);
                water=max(water,area);
                ++left;
            }
            else 
            {
                int area=height[right]*(right-left);
                water=max(water,area);
                --right;
            }
        }
        return water;
    }
};
```