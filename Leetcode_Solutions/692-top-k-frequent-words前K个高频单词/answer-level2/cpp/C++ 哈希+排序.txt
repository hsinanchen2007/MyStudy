### 解题思路
1. 利用哈希版本的Map统计每个单词的出现次数
2. 将统计到的每个单词拷贝到vector中
3. 按照统计值排序前K个
4. 只保留前K个元素返回

### 代码

```cpp
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hashMap;
        for (const auto &word : words) {
            auto it = hashMap.find(word);
            if (it != hashMap.end()) {
                it->second++;
            } else {
                hashMap[word] = 1;
            }
        }
        vector<string> ret(hashMap.size());
        auto it = ret.begin();
        auto hit = hashMap.begin();
        for (;it != ret.end(); it++, hit++) {
            *it = hit->first;
        }
        partial_sort(ret.begin(), ret.begin() + k, ret.end(),
                     [&hashMap](const string &lhs, const string &rhs) {
                         auto lt = hashMap[lhs];
                         auto rt = hashMap[rhs];
                         return lt > rt || lt == rt && lhs < rhs;
                     });
        ret.resize(k);
        return ret;
    }
};
```