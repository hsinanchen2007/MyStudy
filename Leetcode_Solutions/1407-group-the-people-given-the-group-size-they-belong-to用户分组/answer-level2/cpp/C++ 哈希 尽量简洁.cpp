思路：
由于已经知道最大长度为500，用长度为500的vector作为哈希保存。
key为groupSize，value为对应的分组。
value的size等于groupSize，move到结果中。

```
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> record(500, vector<int>());
        vector<vector<int>> result;
        for (int i = 0; i < groupSizes.size(); i++) {
            record[groupSizes[i]].emplace_back(i);
            if (record[groupSizes[i]].size() == groupSizes[i]) {
                result.emplace_back(move(record[groupSizes[i]]));
            }
        }
        return result;
    }
};
```
