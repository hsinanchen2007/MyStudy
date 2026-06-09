堆都会用, 但这里桶排序更快, O(N L log L), L是最长桶长. 当然也可以用 trie 进一步优化成 O(N), 懒得写了
```cpp
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        vector<set<string>> buckets(n + 1);
        unordered_map<string, int> m;
        for (auto &&w : words) {
            ++m[w];
        }
        for (auto &&[w, cnt] : m) {
            buckets[cnt].emplace(w);
        }
        vector<string> ans;
        for (int i = n; i && ans.size() < k; --i) {
            if (buckets[i].size()) {
                ans.insert(end(ans), begin(buckets[i]), end(buckets[i]));
            }
        }
        return {begin(ans), begin(ans) + k};
    }
};
```