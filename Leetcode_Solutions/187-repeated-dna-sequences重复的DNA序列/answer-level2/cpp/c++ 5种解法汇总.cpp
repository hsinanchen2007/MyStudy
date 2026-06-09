最优算法见评论区【金木盐】的题解，这里罗列下5种其他的解法对照一下
```
// 原始string hash法
// 执行用时 :160 ms, 在所有 C++ 提交中击败了 37.18% 的用户
// 内存消耗 :24 MB, 在所有 C++ 提交中击败了 60.00% 的用户
class Solution1 {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int K = 10;
        map<string, int> m;
        vector<string> res;
        if (s.size() < K + 1)
            return res;
        for (int i = 0; i <= s.size() - K; ++i) {
            ++m[s.substr(i, K)];
        }
        for (auto kv : m) {
            if (kv.second > 1) {
                res.push_back(kv.first);
            }
        }
        return res;
    }
};

// 序列转数字的二叉搜索树法
// 执行用时 :56 ms, 在所有 C++ 提交中击败了 88.29% 的用户
// 内存消耗 :15.5 MB, 在所有 C++ 提交中击败了 98.13% 的用户
class Solution2 {
public: 
    struct BSTNode {
        int val;
        int cnt;
        BSTNode* left;
        BSTNode* right;
        BSTNode(int v) : val(v), cnt(1), left(NULL), right(NULL) {}
    };
    BSTNode* root;
    BSTNode** searchBST(BSTNode** bst_root, int v) {
        if ((*bst_root) == NULL || (*bst_root)->val == v)
            return bst_root;
        if ((*bst_root)->val > v)
            return searchBST(&(*bst_root)->left, v);
        return searchBST(&(*bst_root)->right, v);
    }
    
    vector<string> findRepeatedDnaSequences(string s) {
        const int K = 10;
        if (s.size() < K + 1)
            return {};
        const int M = (1 << 2 * K) - 1;
        map<char, int> T = {{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};
        vector<string> res;
        int value = 0;
        for (int i = 0; i < K; ++i) value = (value << 2) | T[s[i]];
        root = new BSTNode(value);
        BSTNode** node;
        for (int i = K; i < s.size(); ++i) {
            value = M & (value << 2) | T[s[i]];
            node = searchBST(&root, value);
            if ((*node) == NULL) {
                *node = new BSTNode(value);
            } else {
                if ((*node)->cnt == 1)
                    res.push_back(s.substr(i - K + 1, K));
                ++(*node)->cnt;
            }
        }
        return res;
    }
};

// 序列转数字的hash法
// 执行用时 :116 ms, 在所有 C++ 提交中击败了 48.26% 的用户
// 内存消耗 :18.1 MB, 在所有 C++ 提交中击败了 81.25% 的用户
class Solution3 {
public: 
    vector<string> findRepeatedDnaSequences(string s) {
        const int K = 10;
        if (s.size() < K + 1)
            return {};
        const int M = (1 << 2 * K) - 1;
        map<char, int> T = {{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};
        map<int, int> read_counts;
        vector<string> res;
        int value = 0;
        for (int i = 0; i < K - 1; ++i) value = (value << 2) | T[s[i]];
        for (int i = K - 1; i < s.size(); ++i) {
            value = M & (value << 2) | T[s[i]];
            ++read_counts[value];
            if (read_counts[value] == 2) {
                res.push_back(s.substr(i - K + 1, K));
            }
        }
        return res;
    }
};

// 序列转数字的普通vector法
// 执行用时 :40 ms, 在所有 C++ 提交中击败了 92.25% 的用户
// 内存消耗 :57.9 MB, 在所有 C++ 提交中击败了 5.00% 的用户
class Solution4 {
public: 
    vector<string> findRepeatedDnaSequences(string s) {
        const int K = 10;
        if (s.size() < K + 1)
            return {};
        const int M = (1 << 2 * K) - 1;
        vector<short int> m(1 << 2 * K, 0);
        map<char, int> T = {{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};
        map<int, int> read_counts;
        vector<string> res;
        int value = 0;
        for (int i = 0; i < K - 1; ++i) value = (value << 2) | T[s[i]];
        for (int i = K - 1; i < s.size(); ++i) {
            value = M & (value << 2) | T[s[i]];
            if (m[value] > 1) {
                continue;
            }
            if (m[value] == 1) {
                res.push_back(s.substr(i - K + 1, K));
            }
            ++m[value];
        }
        return res;
    }
};

// 字典树法
// 执行用时 :280 ms, 在所有 C++ 提交中击败了 17.25% 的用户
// 内存消耗 :66.1 MB, 在所有 C++ 提交中击败了 5.00% 的用户
class Solution5 {
public: 
    struct TrieNode {
        int count;
        map<char, TrieNode*> next;
        TrieNode() : count(0) {}
    };
    TrieNode* root;
    Solution5() {
        root = new TrieNode();
    }
    
    vector<string> findRepeatedDnaSequences(string s) {
        const int K = 10;
        if (s.size() < K + 1)
            return {};
        vector<string> res;
        TrieNode* node;
        for (int i = K - 1; i < s.size(); ++i) {
            node = root;
            for (int j = i - K + 1; j <= i; ++j) {
                if (node->next.count(s[j]) == 0)
                   node->next[s[j]] = new TrieNode();
                node = node->next[s[j]];
            }
            if (node->count == 1)
                res.push_back(s.substr(i - K + 1, K));
            ++node->count;
        }
        return res;
    }
};
```
