```c++
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string s0 = "qwertyuiop";
        string s1 = "asdfghjkl";
        string s2 = "zxcvbnm";
        unordered_map<char, int> m;
        for (char c : s0) {
            m[c] = 0;
            m[c - 32] = 0;
        }
        for (char c : s1) {
            m[c] = 1;
            m[c - 32] = 1;
        }
        for (char c : s2) {
            m[c] = 2;
            m[c - 32] = 2;
        }
        vector<string> v;
        for (auto& word : words) {
            int s = 0;
            for (auto c : word) s += m[c];
            if (s == m[word[0]] * word.size()) v.push_back(word);
        }
        return v;
    }
};
```