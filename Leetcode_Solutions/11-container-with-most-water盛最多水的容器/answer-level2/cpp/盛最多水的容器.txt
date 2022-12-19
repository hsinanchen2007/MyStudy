### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0,j = height.size() - 1;
        int max_Area = 0;
        while(i < j){
            if(height[i] <= height[j]){
                max_Area = max(max_Area,(j - i)*height[i]);
                i++;
            }else{
                max_Area = max(max_Area,(j - i)*height[j]);
                j--;
            }
        }
        return max_Area;
    }
};
```