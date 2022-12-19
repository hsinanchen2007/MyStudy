思路：每个字符串反向构建 TrieTree，根结点为 #。之后所有叶子结点高度之和即为答案。

下面上代码

```c++
// TrieTree结构
typedef struct _TrieTree {
    char value;
    int child_count;
    _TrieTree *child_nodes[26];
    _TrieTree *parent;
} TrieTree, *pTrieTree;

class Solution {
private:
    // 回收内存，销毁树
    void clear_tree(pTrieTree root) {
        if (root) {
            for (auto p:root->child_nodes) {
                clear_tree(p);
            }

            delete root;
        }
    }

    // 创建一个树节点
    pTrieTree new_tree_node(char value, pTrieTree parent = NULL) {
        auto p = new TrieTree();
        p->value = value;
        p->parent = parent;
        p->child_count = 0;

        return p;
    }

    // 在node节点下，增加字符
    bool add_char(pTrieTree node, const char ch) {
        auto p = node->child_nodes[ch - 'a'];
        if (!p) {
            ++node->child_count;
            node->child_nodes[ch - 'a'] = new_tree_node(ch, node);
            return true;
        }
        return false;
    }

    // 在根节点下，增加字符串
    void add_word(pTrieTree root, const std::string &word) {
        if (word.empty()) {
            return;
        }

        size_t word_len = word.size();
        pTrieTree p = root;
        for (int i = word_len - 1; i >= 0; --i) {
            char current = word[i];
            add_char(p, current);
            p = p->child_nodes[current - 'a'];
        }
    }

    // 根据原始输入，构建树
    pTrieTree build_tree(std::vector<std::string> &words) {
        auto root = new_tree_node('#');
        for (auto &word:words) {
            add_word(root, word);
        }
        return root;
    }

    int calc_tree_count(pTrieTree root) {
        return tree_count(root, 1);
    }

    // DFS计算所有叶子结点高度之和
    int tree_count(pTrieTree node, int level) {
        if (!node) {
            return 0;
        }
        if (0 == node->child_count) {
            return level;
        }
        int result = 0;
        for (auto p:node->child_nodes) {
            result += tree_count(p, level + 1);
        }
        return result;
    }

public:
    int minimumLengthEncoding(std::vector<std::string> &words) {
        if (words.empty()) {
            return 0;
        }

        auto root = build_tree(words);
        int result = calc_tree_count(root);
        clear_tree(root);

        return result;
    }
};
```
