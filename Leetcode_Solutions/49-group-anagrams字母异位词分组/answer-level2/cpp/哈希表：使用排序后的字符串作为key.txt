### 解题思路
所有的anagrams在排序后相同，如`"eat", "tea", "ate"`在排序后都是`"aet"`。这给了我们一种提示，我们可以将排序后的结果作为判断的依据来确定两个字符串是否是anagram关系。为此目的，我们使用一个哈希表，其key为字符串排序后的结果，如果该key未出现在哈希表中，则我们遇到了一个新的anagram，否则应添加进已存在的anagram中。

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        
        for (const auto& str : strs) {
            auto k = str;
            sort(k.begin(), k.end());
            if (m.find(k) == m.end()) {
                m[k] = {str};
            } else {
                m[k].push_back(str);
            }
        }
        
        vector<vector<string>> res;
        for (auto& [k, v] : m) res.push_back(v);
        return res;
    }
};
```