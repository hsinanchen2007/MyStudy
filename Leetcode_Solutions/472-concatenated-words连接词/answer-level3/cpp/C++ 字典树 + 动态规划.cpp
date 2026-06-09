```
class Solution {
public:
    struct TrieTree {
        bool flag;
        map<char, TrieTree*> next;
        TrieTree() : flag(false) {}
    };
    TrieTree* root;
    void init(const vector<string>& words) {
        root = new TrieTree;
        for (auto& w : words) {
            auto node = root;
            for (auto c : w) {
                if (node->next.count(c) == 0) {
                    node->next[c] = new TrieTree;
                }
                node = node->next[c];
            }
            node->flag = true;
        }
    }
    bool valid(const string& s) {
        int n = s.size();
        vector<vector<int> > dp(n + 1);
        dp[0] = {-1};
        for (int i = 0; i < n; ++i) {
            if (dp[i].empty() || root->next.count(s[i]) == 0) continue;
            int j = i;
            auto node = root;
            while (j < n && node->next.count(s[j])) {
                node = node->next[s[j++]];
                if (node->flag) {
                    if (i != 0 && j == n) return true;
                    dp[j].push_back(i);
                }
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        init(words);
        vector<string> res;
        for (auto& w : words) {
            if (valid(w)) {
                res.push_back(w);
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/ecab1f89cccfd36f49bfdd54e8913085eb9e74e9302b867973c2ebc1a0e0b9e5-image.png)
