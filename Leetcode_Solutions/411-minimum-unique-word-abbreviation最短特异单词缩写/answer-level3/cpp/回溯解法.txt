### 解题思路
深搜解法

### 代码

```cpp
class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        auto check = [](string& word, string& abbr)->bool{
            int i = 0, j = 0;
            while (i < abbr.size() && j < word.size()) {
                int cnt = 0;
                while (i < abbr.size() && isdigit(abbr[i])) {
                    if (cnt == 0 && abbr[i] == '0') {
                        return false;
                    }
                    cnt = cnt * 10 + abbr[i++] - '0';
                }
                j += cnt;
                while (i < abbr.size() && islower(abbr[i]) && j < word.size()) {
                    if (abbr[i++] != word[j++]) {
                        return false;
                    }
                }
            }
            return i == abbr.size() && j == word.size();
        };
        int m = target.size();
        vector<string> dict;
        for (auto& e : dictionary) {
            if (e.size() == m) {
                dict.push_back(e);
            }
        }
        if (dict.empty()) {
            return to_string(m);
        }
        string ans;
        function<bool(int, int, int, string, int, bool)> dfs = [&](int i, int j, int k, string abbr, int pos, bool num)->bool{
            if (pos == m) {
                for (auto& e : dict) {
                    if (check(e, abbr)) {
                        return false;
                    }
                }
                ans = abbr;
                return true;
            }
            if (num) {
                int r = i > 0 ? i - 1 : 0;
                int b = j - r;
                do {
                    if (dfs(i, j - b, k, abbr + target.substr(pos, b), pos + b, false)) {
                        return true;
                    }
                    b--;
                } while (b > 0 && i > 0);
            } else {
                int a = k - (i - 1);
                do {
                    if (dfs(i - 1, j, k - a, abbr + to_string(a), pos + a, true)) {
                        return true;
                    }
                    a--;
                } while (a > 0 && i > 1);
            }
            return false;
        };
        for (int l = 2; l <= m; l++) {
            for (int i = 1, j = l - i; i < l && i <= j + 1; i++, j--) {
                int k = m - j;
                if (dfs(i, j, k, "", 0, true)) {
                    return ans;
                }
                int a = k - (i - 1); 
                do {
                    if (dfs(i - 1, j, k - a, to_string(a), a, true)) {
                        return ans;
                    }
                    a--;
                } while (a > 0 && i > 1);
            }
        }
        return target;
    }
};
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
```