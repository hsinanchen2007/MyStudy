### 解题思路
* 排序+哈希
* 将每个单词排序，得到唯一的key，对于的value用字符数组存储vector<string>

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
        unordered_map<string, vector<string>> map;
        for(string str: strs) {
            string tmpStr = str;
            sort(tmpStr.begin(), tmpStr.end());
            map[tmpStr].push_back(str);
        }
        vector<vector<string>> GpAnagram;
        for(auto a: map) {
            GpAnagram.push_back(a.second);
        }
        return GpAnagram;
    }
};
```

![2.png](https://pic.leetcode-cn.com/246544f2eeae633de5eb049cf47be09f0dc66ddc66059dbda85d6662fd6c8e9d-2.png)
