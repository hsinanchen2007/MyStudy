方法一：

给定字符串 big，我们可以对 big 及所有的后缀组成的字符串集构造一颗字典树，如 abcd，则集合为 {abcd, bdc, dc, c}。

- 树的构建：节点包含经过这个节点的字符串的首字母的位置，节点的位置集合在构建树的时候生成。

- 查询：对于 smalls 中的每一个单词，从字典树中查找，如果找到，返回最后一个节点的位置集合；如果找不到，直接返回空的 vector。

代码如下：

```
typedef struct TrieNode {
    TrieNode* next[26] = {NULL};
    vector<int> pos; // 经过这个节点的字符串的首字母的位置集合
    TrieNode() {}
} * Trie;

class Solution {
   public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        vector<vector<int>> res;
        if (big.size() == 0) {
            res.resize(smalls.size());
            return res;
        }

        Trie trie = new TrieNode();
        for (int i = 0; i < big.size(); i++) {
            buildTrie(trie, big.substr(i, big.size() - i), i);
        }

        for (string small : smalls) {
            res.push_back(find(trie, small));
        }

        return res;
    }

    vector<int> find(Trie root, string small) {
        vector<int> res;
        if (small.size() == 0) return res;

        Trie p = root;
        for (char c : small) {
            int pos = c - 'a';
            if (p->next[pos]) {
                p = p->next[pos];
            } else {
                return res;
            }
        }
        return p->pos;
    }

    void buildTrie(Trie root, string str, int pos) {
        Trie p = root;
        for (char c : str) {
            int index = c - 'a';
            if (p->next[index] == NULL) {
                p->next[index] = new TrieNode();
            }
            p->next[index]->pos.push_back(pos);
            p = p->next[index];
        }
    }
};
```

方法二：

对 smalls 中的每一个单词添加到字典树中，然后在树中查找 big 及 big 的所有后缀字符串，如果 big 经过的节点有 leaf 标志，则将 big首字母的位置添加到对应的 small 中。

```
typedef struct TrieNode {
    TrieNode* next[26] = {NULL};
    bool leaf;
    TrieNode() : leaf(false) {}
} * Trie;

class Solution {
   public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        vector<vector<int>> res;
        if (big.size() == 0) {
            res.resize(smalls.size());
            return res;
        }

        Trie trie = new TrieNode();
        for (string str : smalls) buildTrie(trie, str);

        // 查找 big 及其后缀字符串
        for (int i = 0; i < big.size(); i++) {
            find(trie, big.substr(i, big.size() - i), i);
        }

        for (string str : smalls) res.push_back(mm[str]);

        return res;
    }

   private:
    void find(Trie root, string str, int index) {
        Trie p = root;
        int i = 0;
        for (char c : str) {
            int pos = c - 'a';
            if (p->next[pos]) {
                // 从根节点到当前是 small 中的单词
                if (p->next[pos]->leaf)
                    mm[str.substr(0, i + 1)].push_back(index);
                p = p->next[pos];
                i++;
            } else {
                return;
            }
        }
    }

    void buildTrie(Trie root, string str) {
        Trie p = root;
        for (char c : str) {
            int index = c - 'a';
            if (p->next[index] == NULL) p->next[index] = new TrieNode();
            p = p->next[index];
        }
        p->leaf = true;
    }

    unordered_map<string, vector<int>> mm;
};
```

2中方法的缺点是空间复杂度较高。