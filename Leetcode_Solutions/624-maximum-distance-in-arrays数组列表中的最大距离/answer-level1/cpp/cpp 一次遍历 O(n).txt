# **容易出错的地方**：
可能最大最小的都在**一个vector**里面

# **思路：**
1.保存当前最大和最小
2.遍历，当前vector的最大和最小和之前保存的比较，更新距离
3.更新最大和最小，继续遍历

# **代码：**
```
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int dist = 0;
        int max = arrays[0].back();
        int min = arrays[0].front();
        for (int i = 1; i < arrays.size(); i++) {
            dist = std::max(dist, std::max(arrays[i].back() - min, max - arrays[i].front()));
            max = std::max(arrays[i].back(), max);
            min = std::min(arrays[i].front(), min);
        }
        return dist;
    }
};
```
