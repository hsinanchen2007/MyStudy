1，字典树加速匹配速度
2，记忆化搜索减少重复计算
```
class Solution {
public:
    struct TrieNode {
        bool flag;
        map<char, TrieNode*> next;
        TrieNode() : flag(false) {}
    };
    TrieNode* root;
    vector<int> memo;
    bool func(string& s, int start, int end) {
        if (start == end)
            return true;
        if (memo[start] != 0)
            return memo[start] > 0;
        auto node = root;
        for (int i = start; i < end; ++i) {
            if (node->next.count(s[i]) == 0)
                break;
            node = node->next[s[i]];
            if (node->flag && func(s, i + 1, end)) {
                memo[start] = 1;
                return true;
            }
        }
        memo[start] = -1;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memo = vector<int>(s.size(), 0);
        root = new TrieNode();
        auto node = root;
        for (auto w : wordDict) {
            node = root;
            for (auto c : w) {
                if (node->next.count(c) == 0)
                    node->next[c] = new TrieNode();
                node = node->next[c];
            }
            node->flag = true;
        }
        return func(s, 0, s.size());
    }
};
```
![image.png](https://pic.leetcode-cn.com/b8af9a7e7e711195e833ec167d4b68c985c41744a60fab27f3b921ad0e3da91d-image.png)
