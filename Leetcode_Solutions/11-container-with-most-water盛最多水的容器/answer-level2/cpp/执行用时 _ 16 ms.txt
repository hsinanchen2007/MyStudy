### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int max_a = 0,i = 0,j = len - 1;
        while( i < j)
            max_a = max(max_a,(j - i) * (height[i] < height[j] ? height[i++] : height[j--]));
        return max_a;
    }
};
```