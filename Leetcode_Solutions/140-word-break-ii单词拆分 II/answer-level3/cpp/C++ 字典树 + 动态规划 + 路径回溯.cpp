1，构建字典树加速搜索
2，动态规划，`dp[j]`代表截止到`j - 1`位置处最后一个单词所有可能的起始位置
3，根据最后一个dp值进行DFS路径回溯，获取到所有的可能结果
```
class Solution {
public:
    struct TrieNode {
        bool flag;
        map<char, TrieNode*> next;
        TrieNode() : flag(false) {}
    };
    TrieNode* root;
    void init(const vector<string>& words) {
        root = new TrieNode;
        for (auto& w : words) {
            auto node = root;
            for (auto c : w) {
                if (!node->next.count(c)) {
                    node->next[c] = new TrieNode;
                }
                node = node->next[c];
            }
            node->flag = true;
        }
    }
    
    void dfs(const string& s, const vector<vector<int> >& dp, int i, vector<string>& v, vector<string>& res) {
        if (i == 0) {
            string t;
            for (auto it = v.rbegin(); it != v.rend(); ++it) {
                t += *it + " ";
            }
            t.pop_back();
            res.push_back(t);
            return;
        }
        for (auto j : dp[i]) {
            v.push_back(s.substr(j, i - j));
            dfs(s, dp, j, v, res);
            v.pop_back();
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // 构建字典树
        init(wordDict);
        unordered_set<char> cs;
        for (auto& w : wordDict) {
            for (auto c : w) {
                cs.insert(c);
            }
        }
        for (auto c : s) {
            if (cs.count(c) == 0) {
                return {};
            }
        }
        // 动态规划部分
        int N = s.size();
        vector<vector<int> > dp(N + 1);
        dp[0] = vector<int>{-1};
        for (int i = 0; i < N; ++i) {
            if (dp[i].empty()) continue;
            int j = i;
            auto node = root;
            while (j < N && node->next.count(s[j])) {
                node = node->next[s[j++]];
                if (node->flag) {
                    dp[j].push_back(i);
                }
            }
        }
        // 路径回溯构建所有可能的结果字符串
        vector<string> v;
        vector<string> res;
        dfs(s, dp, N, v, res);
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/98f1b3f9194ad6049185d3325554a0db4bae25f55a0fab5c563291332e364607-image.png)
