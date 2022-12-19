```
class Solution {
public:
    unordered_map<char,int> map;
    vector<string> res;
    string singleChar = "";
    int len = 0;
    vector<string> generatePalindromes(string s) {
        for (char c : s) map[c]++;
        int count = 0;
        for (auto &it : map) {
            if (it.second & 1) {
                count++;
                singleChar.push_back(it.first);
            }
            it.second /= 2;
        }
        if (count > 1) return {};
        len = s.size() / 2;
        dfs("", 0);
        return res;
    }

    void dfs(string cur, int n) {
        if (n == len) {
            res.push_back(cur + singleChar + string(cur.rbegin(), cur.rend()));
            return;
        }
        for (auto &it : map) {
            if (it.second != 0) {
                cur.push_back(it.first);
                it.second--;
                dfs(cur, n + 1);
                it.second++;
                cur.pop_back();
            }
        }
    }
};
```
