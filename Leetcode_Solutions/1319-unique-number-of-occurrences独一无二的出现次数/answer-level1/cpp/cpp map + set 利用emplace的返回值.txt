```
class Solution {
public:
    inline bool uniqueOccurrences(vector<int>& arr) {
        std::map<int, int> temp;
        for (auto num : arr) {
            ++temp[num];
        }
        std::set<int> checker;
        for (const auto& [num, count] : temp) {
            if (!checker.emplace(count).second) {
                return false;
            }
        }
        return true;
    }
};
```
