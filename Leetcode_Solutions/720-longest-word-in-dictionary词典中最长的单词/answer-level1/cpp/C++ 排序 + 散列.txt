### 代码
```cpp
class Solution {
private:
    static bool cmp(const string& a, const string& b) {
        return a.length() != b.length() ? a.length() > b.length() : a < b;
    }
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        unordered_set<string> hash;
        for (string s : words) hash.insert(s);
        for (string s : words) {
            size_t len;
            for (len = 1; len < s.length(); len++)
                if (hash.find(s.substr(0, len)) == hash.end()) break;
            if (len == s.length()) return s;
        }
        return "";
    }
};
```