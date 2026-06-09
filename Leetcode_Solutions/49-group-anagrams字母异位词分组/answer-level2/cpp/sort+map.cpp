### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> result;
        if (strs.size() == 0) return result;
        auto temp_strs(strs);
        for (auto& str : temp_strs) {
            sort(str.begin(), str.end());
        }
        map<string, vector<int>> res;
        for (int i = 0; i < strs.size(); ++i) {
            res[temp_strs[i]].push_back(i);
        }
        result.resize(res.size());
        int k = 0;
        for (auto node : res) {
            auto index = node.second;
            for (int i = 0; i < index.size(); ++i) {
                result[k].push_back(strs[index[i]]);
            }
            ++k;
        }
        return result;
    }
/*
    bool comp_str(map<char, int>& str1, 
            map<char, int>& str2, const string& str) {
        for (auto ch : str) {
            if (str1[ch] != str2[ch]) return false;
        }
        return true;
    }*/
};
```