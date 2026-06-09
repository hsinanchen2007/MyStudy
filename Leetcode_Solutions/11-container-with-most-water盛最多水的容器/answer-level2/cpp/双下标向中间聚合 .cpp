### 解题思路
维护两个下标，分别初始化在两端，循环过程中，如果哪个下标对应的高度小就将其向中间移动，直到两下标相遇。

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int area = 0;
        int max = 0;
        while(left<right){
            area = (right-left)*min(height[left],height[right]); 
            max = area > max ? area : max ;
            if(height[left]>height[right]){
                right = -- right;
            }
            else ++left;
        }
        return max;
        
    }
};
```