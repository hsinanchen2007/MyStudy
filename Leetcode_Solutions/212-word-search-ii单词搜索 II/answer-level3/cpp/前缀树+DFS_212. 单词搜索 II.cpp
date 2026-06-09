### 解题思路
    /*
     * 前缀树+DFS
     *
     * 由于直接使用DFS算法会超时，将字符串数组中的字符串构建为前缀树，能够提高查询效率。
     * 构建前缀树，当遍历矩阵中的点时，判断该点所在字符串是否满足前缀树，
     * 若满足则将该字符串存储到结果数组中，不满足则继续遍历。
     *
     * 深度优先遍历的流程相同：
     * 1. 递归结束；
     * 2. 判断是否满足；
     * 3. 修改遍历的字符避免重复访问，
     * 4. 以当前访问的点开始，对其上下左右的点的字符进行递归遍历；
     * 5. 遍历结束后将修改的字符还原。
     * */
### 代码

```cpp
    // 构建前缀树
    struct TrieNode {
        std::vector<TrieNode *> child;
        std::string word;

        TrieNode() : child(std::vector<TrieNode *>(26, nullptr)), word("") {}
    };

std::vector<std::string>
findWords(std::vector<std::vector<char>> &board, std::vector<std::string> &words) {
    // 构建前缀树
    TrieNode *root = buildTrie(words);
    std::vector<std::string> ans;

    // 对字符矩阵进行遍历
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            // 使用DFS算法进行查找
            dfs(board, words, root, ans, i, j);
        }
    }

    return ans;
}

void
dfs(std::vector<std::vector<char>> &board, std::vector<std::string> &words, TrieNode *root,
                 std::vector<std::string> &ans, int x, int y) {
    // 当前字符
    char ch = board[x][y];

    // 递归结束条件
    if (ch == '#' || root->child[ch - 'a'] == nullptr) {
        return;
    }

    // 搜索前缀树
    root = root->child[ch - 'a'];
    // 将查找到的字符串存入结果数组
    if (root->word.size() > 0) {
        ans.push_back(root->word);
        root->word = "";
    }

    // 遍历过当前的字符后，
    // 为避免重复访问，将该字符修改为字符#
    board[x][y] = '#';

    // 从该字符开始，对其左字符进行递归遍历
    if (x - 1 >= 0 && x - 1 < board.size() && y >= 0 && y < board[0].size()) {
        dfs(board, words, root, ans, x - 1, y);
    }

    // 从该字符开始，对其右字符进行递归遍历
    if (x + 1 >= 0 && x + 1 < board.size() && y >= 0 && y < board[0].size()) {
        dfs(board, words, root, ans, x + 1, y);
    }

    // 从该字符开始，对其上字符进行递归遍历
    if (x >= 0 && x < board.size() && y - 1 >= 0 && y - 1 < board[0].size()) {
        dfs(board, words, root, ans, x, y - 1);
    }

    // 从该字符开始，对其下字符进行递归遍历
    if (x >= 0 && x < board.size() && y + 1 >= 0 && y + 1 < board[0].size()) {
        dfs(board, words, root, ans, x, y + 1);
    }

    // 还原字符矩阵中该点的字符
    board[x][y] = ch;
}

TrieNode *buildTrie(std::vector<std::string> &words) {
    TrieNode *root = new TrieNode();
    for (std::string word : words) {
        TrieNode *curNode = root;
        for (char ch : word) {
            int i = ch - 'a';
            if (curNode->child[i] == nullptr) {
                curNode->child[i] = new TrieNode();
            }
            curNode = curNode->child[i];
        }
        curNode->word = word;
    }

    return root;
}
```