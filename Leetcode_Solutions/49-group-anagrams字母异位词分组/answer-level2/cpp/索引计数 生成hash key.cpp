### 解题思路
使用一个26个元素的数组，统计每个字符串中字符出现的个数，将该数组转换为一个字符串，即生成了hash key
key相同，则字符串属于同一组
### 代码

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) {
            return vector<vector<string>>();
        }
        
        vector<vector<string>> res;
        int arr[26];
        map<string, int> imap;
        string key;
        key.reserve(sizeof(arr));
        char* parr = (char *)arr;
        for (auto& s : strs) {
            memset(arr, 0, sizeof(arr));
            for (auto c : s) {
                ++arr[c - 'a'];
            }
            // key的长度为数组长度
            key = string(parr, sizeof(arr));
            auto it = imap.find(key);
            if (it == imap.end()) {
                res.push_back(vector<string>());
                res.back().push_back(s);
                imap[key] = res.size() - 1;
            } else {
                res[it->second].push_back(s);
            }
        }

        return res;
    }
};
```