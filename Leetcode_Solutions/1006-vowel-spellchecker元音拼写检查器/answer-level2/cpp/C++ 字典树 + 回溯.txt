看到题第一个想法就是用字典树 + 回溯法，跑的不快，也算一种方案吧
```
class Solution {
public:
    struct TreeNode {
        int ind;
        map<char, TreeNode*> next;
        TreeNode() : ind(-1) {}
    };
    TreeNode* root;
    const unordered_set<char> S{'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    void init(const vector<string>& words) {
        root = new TreeNode();
        for (int i = 0; i < words.size(); ++i) {
            auto node = root;
            for (auto c : words[i]) {
                if (node->next.count(c) == 0) {
                    node->next[c] = new TreeNode();
                } 
                node = node->next[c];
            }
            if (node->ind == -1)
                node->ind = i;
        }
    }
    char upper(char x) { return (x >= 'a' && x <= 'z') ? x + 'A' - 'a' : x; }
    char lower(char x) { return (x >= 'A' && x <= 'Z') ? x + 'a' - 'A' : x; }
    void backtrace(const string& s, TreeNode* node, int i, bool change_case, bool change_char, 
            int& min_ind1, int& min_ind2, int& min_ind3) {
        if (min_ind1 != -1) return;
        if (min_ind2 != -1 && change_char) return;
        if (i == s.size()) {
            if (node->ind == -1) return;
            if (change_char) {
                if (min_ind3 == -1) min_ind3 = node->ind;
                else min_ind3 = min(min_ind3, node->ind);
            } else if (change_case) {
                if (min_ind2 == -1) min_ind2 = node->ind;
                else min_ind2 = min(min_ind2, node->ind);
            } else {
                min_ind1 = node->ind;
            }
            return;
        }
        set<char> cs{lower(s[i]), upper(s[i])};
        if (S.find(s[i]) != S.end()) cs.insert(S.begin(), S.end());
        for (auto c : cs) {
            if (node->next.count(c) > 0) {
                backtrace(s, node->next[c], i + 1, 
                        change_case || (lower(s[i]) == lower(c) && s[i] != c),
                        change_char || (lower(s[i]) != lower(c)),
                        min_ind1, min_ind2, min_ind3);
            }
        }
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        init(wordlist);
        vector<string> res;
        int min_ind1, min_ind2, min_ind3;
        for (const auto& s : queries) {
            min_ind1 = -1; // 完全匹配
            min_ind2 = -1; // 大小写修改可匹配
            min_ind3 = -1; // 修改元音字母可匹配
            backtrace(s, root, 0, false, false, min_ind1, min_ind2, min_ind3);
            if (min_ind1 != -1) {
                res.push_back(wordlist[min_ind1]);
            } else if (min_ind2 != -1) {
                res.push_back(wordlist[min_ind2]);
            } else if (min_ind3 != -1) {
                res.push_back(wordlist[min_ind3]);
            } else {
                res.push_back("");
            }
        }
        return res;
    }
};
```
跑的跑，内存占用高，orz
![image.png](https://pic.leetcode-cn.com/00db90f5f3f57d6d1185b8c28baa48c4ad0bcbcdcde8075c2e364bd3e172219d-image.png)
