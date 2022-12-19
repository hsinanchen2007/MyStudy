用户所在分组人数是固定的，使用map维护当前组的人对应放到哪个位置，如果组在map中不存在或者组员满了，就新加一个。

```c++
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        unordered_map<int, int> um;
        for (int i = 0; i < groupSizes.size(); ++i) {
            if (um.find(groupSizes[i]) == um.end() || res[um[groupSizes[i]]].size() >= groupSizes[i]) {
                um[groupSizes[i]] = res.size();
                res.push_back({i});
            }
            else if (res[um[groupSizes[i]]].size() < groupSizes[i]) {
                res[um[groupSizes[i]]].push_back(i);
            }
        }
        return res;
    }
};
```