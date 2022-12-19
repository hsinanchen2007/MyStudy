### 解题思路一 删除后缀单词
    /*
     * 删除后缀单词
     *
     * 如果单词a是单词b的后缀，则根据题目规则，编码单词b时已经编码过单词a，则可以省略单词a。
     * 如果单词a不在任何其他单词b的后缀中出现，则单词a一定是编码的字符串的一部分。
     * 所以要计算的是所有不是其他单词后缀的单词的长度和，再加上每个单词后的#符号的总长度。
     * 由数据范围可知一个单词最多含有7个后缀，所以可以枚举单词所有的后缀。
     * 对于每个后缀，如果其存在与words列表中，就将其从列表中删除，最后计数列表中未删除的单词即可。
     * */
### 代码

```cpp
int minimumLengthEncoding(std::vector<std::string> &words) {
    if (words.empty()) {
        return 0;
    }

    // 如果单词数组只有一个单词，
    // 返回单词的长度加1
    if (words.size() == 1) {
        return words[0].size() + 1;
    }

    // 使用哈希集合存储单词列表
    std::unordered_set<std::string> wordSet(words.begin(), words.end());

    // 遍历单词列表
    for (auto word : words) {
        // 遍历每个单词的后缀
        for (int i = 1; i < word.size(); i++) {
            // word.substr(i)表示从i开始到单词结尾的后缀单词
            // 如果后缀单词存在与单词列表中，就删除该后缀
            wordSet.erase(word.substr(i));
        }
    }

    // 计算剩下的不是后缀单词的长度加1的和
    int ans = 0;
    for (auto word : wordSet) {
        ans += word.size() + 1;
    }

    return ans;
}
```

### 解题思路二 字典树
    /*
     * 字典树
     *
     * 要计算所有不是其他单词后缀的单词，可以使用字典树。因为字典树是前缀树，所有需要将单词逆序插入树中。
     * 如果单词a是单词b的后缀，则单词a在字典树中遍历时是达到不了叶节点的，而叶节点是单词b的尾字符。
     * 所以字典树的叶子节点所在的单词就代表不是其他单词后缀的单词，
     * 统计叶子节点代表的单词长度再加一的和，就是需要计算的编码后字符串的长度。
     * */
### 代码

```cpp
int minimumLengthEncoding2(std::vector<std::string> &words) {
    if (words.empty()) {
        return 0;
    }

    // 如果单词数组只有一个单词，
    // 返回单词的长度加1
    if (words.size() == 1) {
        return words[0].size() + 1;
    }

    // 字典树根节点
    TrieNode* trie = new TrieNode();
    // 使用哈希表存储字典树的节点及其对应在单词列表中的索引
    std::unordered_map<TrieNode*, int> nodes;

    // 遍历单词列表
    for(int i = 0; i < words.size(); i++){
        // 当前单词
        std::string word = words[i];
        // 当前字典树节点
        TrieNode* curNode = trie;

        // 将当前单词逆序插入到字典树中
        for(int j = word.length() - 1; j >= 0; j--){
            curNode = curNode->insert(word[j]);
        }
        // 将节点与单词列表中的索引相匹配
        nodes[curNode] = i;
    }

    int ans = 0;
    for(auto& node : nodes){
        // 如果节点是叶节点，则表示该单词不是后缀单词
        if(node.first->count == 0){
            // 则计算它们的长度加1的和
            ans += words[node.second].length() + 1;
        }
    }

    return ans;
}
```