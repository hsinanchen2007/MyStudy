### 解题思路
使用双指针的思想：
初始化指针为首尾两个指针l，r，面积的计算公式为 min(height[l], height[r]) * (r-l)。
初始化时，宽度是最宽，但是高度不一定是最高，所以面积不一定是最大。因此首尾指针中高度较小的需要往中间靠拢，由于宽度变小，只有高度变高才有可能比原来的面积大。
迭代上述过程直到首尾指针相遇即可。

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0;
        int r = height.size() - 1;

        while(l < r){
            int h = min(height[l], height[r]);
            ans = max(ans, h * (r - l));
            if(height[l] < height[r]){
                ++l;
            }else{
                --r;
            }
        }
        return ans;
    }
};
```