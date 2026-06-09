### 解题思路
暴力解法

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        if(height.empty() || height.size() < 3) return 0;
        for(int i = 1; i < height.size(); i++){
            if(height[i] < height[i-1]){
                int h = 0;
                for(int j = i+1; j < height.size(); j++){
                    h = max(h, height[j]);
                }
                if(h >= height[i-1]){
                    res += height[i-1] - height[i];
                    height[i] = height[i-1];
                }
                else if(h < height[i-1] && h >= height[i]){
                    res += h - height[i];
                    height[i] = h;                    
                }
            }
        }
        return res;
    }
};
```