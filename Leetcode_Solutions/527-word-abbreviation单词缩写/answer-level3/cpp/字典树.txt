```cpp
class TrieNode {
public:
    int child[26];
    int cnt;
    TrieNode() {
        fill(begin(child), end(child), 0);
        cnt = 0;
    }
};
class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        int n = dict.size();
        if (n == 0) {
            return {};
        }
        vector<string> res(n);
        vector<vector<TrieNode>> pool(401);
        for (int i = 0; i <= 400; i++) {
            pool[i].emplace_back();
        }
        for (int i = 0; i < n; i++) {
            if (dict[i].size() <= 3) {
                res[i] = dict[i];
            } else {
                int m = dict[i].size();
                int root = 0;
                int ind = dict[i][m - 1] - 'a';
                if (!pool[m][root].child[ind]) {
                    pool[m][root].child[ind] = pool[m].size();
                    pool[m].emplace_back();
                }
                root = pool[m][root].child[ind];
                pool[m][root].cnt++;
                for (int j = 0; j < m - 3; j++) {
                    ind = dict[i][j] - 'a';
                    if (!pool[m][root].child[ind]) {
                        pool[m][root].child[ind] = pool[m].size();
                        pool[m].emplace_back();
                    }
                    root = pool[m][root].child[ind];
                    pool[m][root].cnt++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int m = dict[i].size();
            if (m > 3) {
                int len = 0;
                do {
                    int root = 0;
                    int ind = dict[i][m - 1] - 'a';
                    root = pool[m][root].child[ind];
                    if (pool[m][root].cnt <= 1) {
                        len = 1;
                        break;
                    }
                    for (int j = 0; j < m - 3; j++) {
                        ind = dict[i][j] - 'a';
                        root = pool[m][root].child[ind];
                        if (pool[m][root].cnt <= 1) {
                            len = 1 + j;
                            break;
                        }
                    }
                } while (false);
                if (len == 0) {
                    res[i] = dict[i];
                } else {
                    res[i] = dict[i].substr(0, len) + to_string(m - len - 1) + dict[i].substr(m - 1);
                }
            }
        }
        return res;
    }
};
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
```