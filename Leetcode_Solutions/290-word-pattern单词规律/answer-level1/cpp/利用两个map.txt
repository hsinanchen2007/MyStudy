### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
private:
    vector<string> split(const string &s) {
        vector<string> res;
        int start = 0;
        for(int i = start+1; i <= s.size();) {
            if (i == s.size() || s[i] == ' ') {
                res.push_back(s.substr(start, i-start));
                start = i + 1;
                i = start + 1;
            } else {
                i++;
            }            
        }
        return res;
    }

public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        vector<string> words = split(str);
        if(pattern.size() != words.size()) {
            return false;
        }
        int n = pattern.size();
        for(int i = 0; i < n; i++) {
            //若没映射过
            if(m1.find(pattern[i]) == m1.end()) {
                if(m2.find(words[i]) != m2.end()) {
                    return false;
                }
                m1[pattern[i]] = words[i];
                m2[words[i]] = pattern[i];
            } else {
                string s = m1[pattern[i]];
                if (s != words[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
```