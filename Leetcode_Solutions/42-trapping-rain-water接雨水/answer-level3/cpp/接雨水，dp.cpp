### 解题思路
left是各个点左边的最大值 left[i] = max(left[i - 1],height[i - 1])
right是各个点右边的最大值 right[i] = max(right[i + 1],height[i + 1])
因为第一个和最后一个左右没有墙壁，最大高度为0

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>left(n),right(n);
        for(int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], height[i - 1]);
        }
        for(int i = n - 2; i >= 0; i--)
        {
            right[i] = max(right[i + 1],height[i + 1]);
        }
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            int level = min (left[i],right[i]);
            cnt += max(0,level - height[i]);
        }
        return cnt;
    }
};
```