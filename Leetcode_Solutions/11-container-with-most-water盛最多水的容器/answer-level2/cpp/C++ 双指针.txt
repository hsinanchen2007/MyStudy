### 解题思路
思路都是一样的：
+ `left`和`right`首先分别指向数组的最左端和最右端，并记录矩阵面积；
+ 将`left`和`right`中较短的垂直线往里移动，因为矩阵长度变小，所以我们要期待获得更长的垂直线
+ 每次移动都保存较大矩阵面积

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int maxWater = 0;
        while(left < right){
            // 保存历史最大值
            maxWater = max(maxWater, min(height[left],height[right])*(right-left));
            // 较短垂直线往里移动
            if(height[left] <height[right]){
                left += 1;
            }else{
                right -= 1;
            }
        }
        return maxWater;
    }
};
```