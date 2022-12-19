### 解题思路
C++，用unordered_map统计词频, 用partical_sort排出top k，应该能更快些。晚些时候手写一个堆。

### 代码

```cpp
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // 次数统计
        unordered_map<string, int> words_frequency_map;
        for (auto w : words) {
            auto it = words_frequency_map.find(w);
            if (it == words_frequency_map.end()) {
                words_frequency_map.insert(make_pair(w, 1));
            }
            else {
                words_frequency_map[w] += 1;
            }
        }

        // 部分排序
        vector<pair<string, int>> words_frequency_vector(words_frequency_map.begin(), words_frequency_map.end());

        std::partial_sort(words_frequency_vector.begin(), words_frequency_vector.begin() + k, words_frequency_vector.end(), [](auto &a, auto &b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        });

        // 生成结果
        vector<string> results;
        for (auto w : words_frequency_vector) {
            if (k == 0) break;
            results.push_back(w.first);
            k--;
        }
        return results;
    }
};
```