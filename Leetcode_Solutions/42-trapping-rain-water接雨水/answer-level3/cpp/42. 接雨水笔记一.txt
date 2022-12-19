### 解题思路
1. 这里使用暴力法来做
2. 由于最边上的2个位置不能积雨水，遍历除最边上2个位置外的其他位置，计算每个位置能接的雨水量
3. 每个位置能接的雨水量=min(maxLeft, maxRight) - height
4. 计算maxLeft和maxRight时需要考虑当前位置

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        // 暴力法，针对每个位置(除去边上2个位置)，分别找到其左边、右边的最高柱子，然后就可以计算当前柱子能接的雨水量=min(maxLeft, maxRight) - height

        int ans = 0;
        int size = height.size();
        for (int i = 1; i < size - 1; i++) {
            int maxLeft = 0, maxRight = 0;
            for (int j = i; j >= 0; j--) {
                maxLeft = max(maxLeft, height[j]);
            }
            for (int j = i; j < size; j++) {
                maxRight = max(maxRight, height[j]);
            }

            ans += min(maxLeft, maxRight) - height[i];
        }

        return ans;
    }
};
```