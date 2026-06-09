### 解题思路
哈希表统计接缝最多的位置（即穿过砖块最少的位置）

### 代码

```cpp
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> mp;
        int res = 0;
        for(const auto& layer: wall)
        {
            int pos = 0, n = layer.size();
            for(int i=0;i<n-1;++i)
            {
                pos += layer[i];
                res = max(res, ++mp[pos]);
            }
        }
        return wall.size()-res;
    }
};
```