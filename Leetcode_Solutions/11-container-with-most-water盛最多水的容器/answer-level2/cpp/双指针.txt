### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int rt = INT_MIN;
        while(i < j){
            rt = max(rt, min(height[i], height[j])*(j-i));
            if(height[i] < height[j]) i++;
            else j--;
        }
        return rt;
    }
};
```