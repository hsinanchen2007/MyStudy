### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        if (text.empty() || first.empty() || second.empty()) {
            return vector<string> ();
        }
        vector<string> res, dict;
        istringstream ss (text);
        string str;
        while (ss >> str) {
            dict.push_back(str);
        }
        for (int i = 0; i < dict.size(); ++i) {
            if (i >= dict.size() - 2) {
                break;
            }
            if (dict[i] == first && dict[i + 1] == second) {
                res.push_back(dict[i + 2]);
                // i += 1;
            }
        }
        return res;
    }
};
```