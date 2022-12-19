### 解题思路
    /*
     * Trie称为前缀树，也称为字典树
     *
     * Trie是一棵多叉树模型，每个节点的分支数量可能有多个，Trie的节点只包含'a'-'z'的字符。
     * 字母映射表 next 能够保存Trie中当前访问的节点的下一个可能出现的所有字符的链接，
     * 可以通过该根节点预知它的所有子节点的值。
     *
     * 插入：
         * 向Trie中插入一个单词word，操作与构建链表类似。
     * 首先从根节点的子节点开始与word的第一个字符进行匹配，一直匹配到树中前缀链上没有对应的字符。
     * 此时创建新的节点，将该不对应的字符插入到链中，直到插入完word的最后一个字符，
     * 同时叶节点的isStr设置为true，表示该word字符串完全匹配。
     *
     * 完全匹配：
     * 在Trie中查找是否存在单词word。
     * 从树的根节点开始，找到与word第一个字符相同的子节点，从该子节点为首的前缀链开始，
     * 对单词word的每个字符一直向下进行匹配，如果出现节点值为空就表示无法查到该单词，
     * 如果匹配到该前缀链的叶节点，且叶节点的isStr是true就表示完全匹配，否则不完全。
     *
     * 前缀匹配：
     * 在Trie中查找是否存在以prefix为前缀的单词。
     * 与完全匹配相同，唯一的区别是，前缀匹配不需要判断是否单词是完全的，即不判断叶节点的isStr是否为真。
     * */
### 代码

```cpp
private:
    // 叶节点判断是否完全匹配
    bool isStr;
    // 字母映射表
    Trie *next[26];

public:
Trie() {
    // 初始化判断符
    isStr = false;
    // 初始化字母映射表next内存为0
    std::memset(next, 0, sizeof(next));
}

~Trie() {
    Trie *root = this;

    // 将不为nullptr的节点内存释放，
    // 指针指向nullptr
    for (auto &i : root->next) {
        if (i == nullptr) {
            continue;
        }
        delete (i);
        i = nullptr;
    }

    root = nullptr;
}

void insert(std::string word) {
    Trie *root = this;

    // 遍历单词word的每个字符
    for (auto w : word) {
        // 如果当前字符为空，则为它创建新的节点
        if (root->next[w - 'a'] == nullptr) {
            root->next[w - 'a'] = new Trie();
        }
        // 指针后移
        root = root->next[w - 'a'];
    }

    // 叶节点置为true
    root->isStr = true;
}

bool search(std::string word) {
    Trie *root = this;
    for (auto w : word) {
        // 当字符匹配时，指针后移
        root = root->next[w - 'a'];
        // 如果节点为空，表示不匹配，返回false
        if (root == nullptr) {
            return false;
        }
    }

    // 判断是否到达叶节点，
    // 即完全匹配
    return root->isStr;
}

bool startsWith(std::string prefix) {
    Trie *root = this;
    for (auto w : prefix) {
        root = root->next[w - 'a'];
        if (root == nullptr) {
            return false;
        }
    }

    // 只要满足前缀的字符被全部匹配
    return true;
}
```