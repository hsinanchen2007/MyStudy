### 解题思路
4ms 94.75%
6.8m 100%
O(n) 时间复杂度
首先找到高的柱子（多个最高没关系）
然后将前面的补全为递增
后面的补全为递减即可
**最后，向在抗击疫情中牺牲的烈士致敬，向遇难的同胞默哀**
### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0; //我也不知道为啥有"[]"这种测试用例
        int ans = 0,max = 0,n = height.size();
        for(int i=0; i<n; ++i) {
            if(height[i] >= height[max]) max = i;
        }
        int cur = height[0];
        for(int i=1; i<max; ++i) { //补全递增或
            if(height[i] < cur) ans += cur-height[i];
            else cur = height[i];
        }
        cur = height[n-1];
        for(int i=n-2; i > max; --i) { //最高柱后面为递减，那么反过来递增即可
            if(height[i] < cur) ans += cur-height[i];
            else cur = height[i];
        }
        return ans;
    }
};
```