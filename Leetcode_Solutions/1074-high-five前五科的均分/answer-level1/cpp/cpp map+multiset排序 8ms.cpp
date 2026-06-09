![image.png](https://pic.leetcode-cn.com/8aaf33c6f07f3c9f9bcd8073910d4955a3e1fa5a3200d543811d1a6ddae5ff33-image.png)

map构造id的映射，value是multiset，能够自动排序
编译器std::reduce不支持，要不可能还能快点
```
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        for (const auto& item : items) {
            auto& record = records_[item[0]];
            auto num = item[1];
            if (record.size() < 5) {
                record.emplace(num);
            } else if (num > *record.begin()) {
                record.erase(record.begin());
                record.emplace(num);
            }
        }
        vector<vector<int>> results;
        for (const auto& [id, record] : records_) {
            vector<int> result = { id, std::accumulate(record.begin(), record.end(), 0)/record.size() };
            results.emplace_back(std::move(result));
        }
        return results;
    }
private:
    std::map<int, std::multiset<int>> records_;
};
```
