### 解题思路
两个数组
一个数组pre表示每个柱子（包含）的左侧的最高值
一个数组back表示每个柱子（包含）的右侧的最高值

两个数组中取低值，减去柱子高度，既是该柱子的存水高度

时间复杂度*O(3n)*
空间复杂度*O(2n)*
### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0)return 0;

        int n = height.size();
        vector<int> pre(n, 0);
        pre[0] = height[0];
        vector<int> back(n, 0);
        back[n - 1] = height[n - 1];

        for(int i = 1; i < n; ++i)
        {
            pre[i] = max(pre[i - 1], height[i]);
        }
        for(int i = n - 2; i >= 0; --i)
        {
            back[i] = max(back[i + 1], height[i]);
        }
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            res += min(pre[i], back[i]) - height[i];
        }
        return res;
        
    }
};
```