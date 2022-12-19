比较容易想到的思路是暴力方式做，需要预排序，时间复杂度O(nlogn)。

另外一种通用的方法是字典树，由于本题只有一次查询，因此字典树的查询速度快的优势未能提现。

#### 1 暴力

暴力解，需要先对products数组预排序，对每个子串遍历一次即可，加速查找可以使用二分查找优化

代码：

```c++
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& ps, string word) {
        sort(begin(ps), end(ps));
        vector<vector<string>> res(word.size());
        for (auto l = 1; l <= word.size(); ++l) {
            auto w = word.substr(0, l);
            // 二分查找，简单优化
            auto it = lower_bound(begin(ps), end(ps), w);
            for (; it != end(ps) && it->substr(0, l) == w && res[l - 1].size() < 3; ++it)
                res[l - 1].push_back(*it);
        }
        return res;
    }
};
```

时间复杂度 O(nlogn)

#### 2 前缀字典树

前缀字典树：建树时的时间成本高，本身内存消耗高，但是每次查询时间非常快。由于题目限制，本题中只有单词查询，因此字典树的查询时间优势无法体现，总体时间空间成本比暴力搜索高很多

代码：

```c++
// 字典树的每个Node
struct TrieNode {
    // 如果只需要判断是否是词结尾，只需要bool即可
    // 需要记录词的个数，需要int计数
    int is_end;
    vector<TrieNode*> son{vector<TrieNode*>(26, NULL)};
    
    TrieNode(int end = 0): is_end(end){}
};

class Trie {
public:
    // 初始化字典树
    Trie() {
        root = new TrieNode();
    }
    
    // 字典树插入新词
    void insert(const string& word) {
        TrieNode* node = root;
        for(char ch : word) {
            if (!node->son[ch - 'a'])
                node->son[ch - 'a'] = new TrieNode();
            node = node->son[ch - 'a'];
        }
        node->is_end++;
    }
    
    TrieNode* find(const string& str) {
        TrieNode* node = root;
        for (char ch : str) {
            if (!node) break;
            node = node->son[ch - 'a'];
        }
        return node;
    }

    // 返回前缀匹配到节点，未匹配到为NULL
    TrieNode* startsWith(const string& prefix) {
        TrieNode* node = find(prefix);
        return node;
    }
    
    vector<string> find3startWith(const string& prefix) {
        vector<string> res;
        // 查找前缀对应的节点
        TrieNode* root = find(prefix);
        if (!root) return res;
        // 前缀存在，深搜找到字典序前三个词
        dfs(root, prefix, res);
        return res;
    }
    
    void dfs(TrieNode* root, string cur, vector<string>& res) {
        if (root->is_end > 0) {
            // 找到一个词，对应加入结果中
            for (int i = 0; i < root->is_end; ++i) {
                if (res.size() >= 3) break;
                res.push_back(cur);
            }
        }
        for (int i = 0; i < root->son.size(); ++i) {
            // 结果数目不能超过3个
            if (res.size() >= 3) break;
            if (root->son[i]) {
                char cur_ch = ('a' + i);
                dfs(root->son[i], cur + cur_ch, res);
            }
        }
    }
private:
    TrieNode* root;
};


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res(searchWord.size());
        // 初始化字典树
        Trie trie = Trie();
        for (string& str: products) {
            // 字典树中插入词
            trie.insert(str);
        }
        string cur = "";
        for (int i = 0; i < searchWord.size(); ++i) {
            cur += searchWord[i];
            res[i] = trie.find3startWith(cur);
        }
        return res;
    }
};
```

