### 解题思路


### 代码
O（n）时间复杂度。
两边夹逼法。

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxV = 0;
        for (int i = 0, j = height.size() - 1; i < j; ) {
            int minHeight = height[i] < height[j] ? height[i++] : height[j--];
            maxV = max(maxV, (j-i+1)*minHeight);
        }
        return maxV;
    }
};
```


class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxV = 0;
        for (int i = 0; i < height.size() - 1; i++) {
            for (int j = i+1; j < height.size(); j++) {
                int minHeight = min(height[i], height[j]);
                maxV = max(maxV, (j-i)*minHeight);
            }
        }
        return maxV;
    }
};