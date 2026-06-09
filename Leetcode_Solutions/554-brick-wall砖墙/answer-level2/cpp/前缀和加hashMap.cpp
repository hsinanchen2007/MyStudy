### 解题思路
统计所有行的前缀和，去掉末尾，统计前缀和相等的个数取最大值，砖墙高度减去这个最大值即为答案

### 代码

```cpp
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall)
    {
        unordered_map<int, int> hashMap;

        for (auto row : wall) {
            long long sum = 0;
            for (int i = 0; i < row.size() - 1; ++i) {
                sum += row[i];
                hashMap[sum]++;
            }
        }

        int num = 0;
        for (auto each : hashMap) {
            num = max(num, each.second);
        }

        return wall.size() - num;
    }
};
```