### 解题思路
首先要注意的是个数不一样
其次需要判断pettern中不同字符对应同一个字符串形式；
其他正常


### 代码

```cpp
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if (str.empty() || pattern.empty()) {
            return false;
        }
        unordered_map<char, string> dict;
        unordered_set<string> st;
        istringstream ss(str);
        string s;
        for (int i = 0; i < pattern.size(); ++i) {
            if (!(ss >> s)) {
                return false;
            }
            if (dict[pattern[i]].empty()) {
                if (st.insert(s).second == false) {
                    return false;
                }
                dict[pattern[i]] = s;
            } else {
                if (dict[pattern[i]] != s) {
                    return false;
                }
            }
        }
        if (ss >> str) {
            return false;
        }
        return true;
    }
};
```