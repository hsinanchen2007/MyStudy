哈希表，注意 "ab":"dog dog" = false, "abba":"dog dog dog dog" = false这两种也算错，所以要用两个互相对比
```c++
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if (pattern.empty() || str.empty()) return false;
        int i = 0;
        vector<string> splited_str;
        //split string
        while (i < str.size()) {
            int pos = str.find(' ', i);
            if (pos == string::npos) {
                splited_str.push_back(str.substr(i, str.size() - i));
                i = str.size();
            } else {
                splited_str.push_back(str.substr(i, pos - i));
                i = pos + 1;
            }
        }
        if (splited_str.size() != pattern.length()) return false;
        // example: "ab":"dog dog" = false, "abba":"dog dog dog dog" = false
        unordered_map<char, string> m;
        unordered_map<string, char> rm;
        for (int j = 0; j < pattern.size(); ++j) {
            if (m.count(pattern[j]) != 0 || rm.count(splited_str[j]) != 0) {
                if (m[pattern[j]] != splited_str[j] || rm[splited_str[j]] != pattern[j]) return false;
            } else {
                m[pattern[j]] = splited_str[j];
                rm[splited_str[j]] = pattern[j];
            }
        }
        return true;
    }
};
```

