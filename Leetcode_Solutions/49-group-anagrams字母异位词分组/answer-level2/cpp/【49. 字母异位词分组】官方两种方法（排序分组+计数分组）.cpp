## 思路一：排序数组分类
1. 对每个单词进行排序，将排序后的单词作为key。
2. 设置哈希表value为相同键的原单词
3. 遍历哈希表，将每个value添加到结果集中。
### 代码
时间复杂度：O(nklogk)，其中n为字符串个数，klogk为排序时间。
空间复杂度：O(nk)。
```c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) return {{}};
        vector<vector<string>> res;
        unordered_map<string, vector<string>> umap;
        for (string str : strs) {
            string tmp = str;            
            sort(tmp.begin(), tmp.end());
            umap[tmp].push_back(str);
        }
        for (auto it : umap) {
            res.push_back(it.second);
        }
        return res;
    }
};
```

## 思路二：按计数分类
将每个字符串映射为26个字符出现的次数。因为有的次数超过10，所以用特殊字符（‘#’）分割每个字母出现的次数。
**避免排序**
### 代码
时间复杂度：O(nk)
空间复杂度：O(nk)
```c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) return {{}};
        vector<vector<string>> res;
        unordered_map<string, vector<string>> umap;
        vector<int> hash(26, 0);
        for (string str : strs) {
            fill(hash.begin(), hash.end(), 0);
            for (char c : str) {
                ++hash[c - 'a'];
            }
            string tmp;
            for (int i = 0; i < hash.size(); ++i) {
                tmp += '#';
                tmp += hash[i];
            }            
            umap[tmp].push_back(str);          
        }
        for (auto it : umap) {
            res.push_back(it.second);
        }
        return res;
    }
};
```



