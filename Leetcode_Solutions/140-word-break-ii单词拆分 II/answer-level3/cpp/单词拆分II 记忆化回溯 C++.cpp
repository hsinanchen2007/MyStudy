```cpp
class Solution {
public:
vector<string> wordBreak(string s, vector<string> &wordDict) {

    unordered_set<string> t(wordDict.begin(), wordDict.end());
    unordered_map<int, vector<string>> m;

    return wordBreak2II_bt(s, t, m, 0);
}

vector<string> wordBreak2II_bt(string s, unordered_set<string> &t, unordered_map<int, vector<string>> &m, int index) {

    if (m.count(index)) {
        return m[index];
    }
    vector<string> ret;
    if (index == s.size()) {
        ret.emplace_back("");
    } else
        for (int i = index + 1; i <= s.size(); ++i) {

            if (t.count(s.substr(index, i - index))) {
                vector<string> tmp = wordBreak2II_bt(s, t, m, i);
                for (auto &j : tmp) {
                    ret.push_back(s.substr(index, i - index) + (j.empty() ? "" : " ") + j);
                }
            }
        }
    m[index] = ret;
    return ret;
}

};


```