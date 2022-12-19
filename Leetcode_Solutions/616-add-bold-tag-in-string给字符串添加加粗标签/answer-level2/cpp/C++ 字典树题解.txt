```cpp
class Solution {
public:
    struct TrieNode {
        bool flag;
        map<char, TrieNode*> next;
        TrieNode() : flag(false) {}
    };
    TrieNode* root;
    Solution() {
        root = new TrieNode();
    }
    void init(const vector<string>& dict) {
        for (auto& w : dict) {
            auto node = root;
            for (auto c : w) {
                if (node->next.count(c) == 0) {
                    node->next[c] = new TrieNode();
                }
                node = node->next[c];
            }
            node->flag = true;
        }
    }
    void dfs(TrieNode* node, const string& s, int N, int i, int& r) {
        if (i >= N) return;
        if (node->next.count(s[i])) {
            node = node->next[s[i]];
            if (node->flag) r = max(r, i);
            dfs(node, s, N, i + 1, r);
        }
    }
    string addBoldTag(string s, vector<string>& dict) {
        init(dict);
        int l = -1;
        int N = s.size();
        vector<bool> contains(N, false);
        string res;
        for (int i = 0; i < N; ++i) {
            int r = -1;
            dfs(root, s, N, i, r);
            for (int j = i; j <= r; ++j) {
                contains[j] = true;
            }
            if (!contains[i]) {
                if (l != -1) {
                    res += "<b>" + s.substr(l, i - l) + "</b>";
                    l = -1;
                }
                res += s[i];
            } else if (l == -1) {
                l = i;
            }
        }
        if (l != -1) {
            res += "<b>" + s.substr(l, N - l) + "</b>";
        }
        return res;
    }
};
```


![image.png](https://pic.leetcode-cn.com/4559e7926cc206210ab520c674a6aa579d640ff4ed14cc848a632f665c89715e-image.png)
