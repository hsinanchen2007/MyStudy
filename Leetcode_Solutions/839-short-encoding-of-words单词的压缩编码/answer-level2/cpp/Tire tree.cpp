具体如何建树可以[看这里，里面还有前缀树的建树方法](https://github.com/Streetlight-bookstand/Algorithm/blob/master/Trie%20Tree.md)
```c++
struct TrieNode {
    TrieNode* next[26];
    TrieNode() {
        memset(next, NULL, sizeof(next));
    }
};

void Insert(TrieNode*& root, string s) {
    TrieNode* local = root, *temp;
    int len = s.size();
    for (int i = len - 1; i >= 0; i--) {
        int id = s[i] - 'a';
        if (local->next[id] != NULL) {
            local = local->next[id];
        } else {
            temp = new TrieNode();
            local->next[id] = temp;
            local = local->next[id];
        }
    }
}

int CountLeaveHeight(TrieNode* root, int height) {
    bool is_leaf = true;
    for (int i = 0; i < 26; i++) {
        if (root->next[i] != NULL) {
            is_leaf = false;
            break;
        }
    }
    if (is_leaf) {
        return height;
    }
    int sum = 0;
    for (int i = 0; i < 26; i++) {
        if (root->next[i]) {
            sum += CountLeaveHeight(root->next[i], height + 1);
        }
    }
    return sum;
}

int minimumLengthEncoding(vector<string>& words) {
    TrieNode* root = new TrieNode();
    for (int i = 0; i < words.size(); i++) {
        Insert(root, words[i]);
    }
    return CountLeaveHeight(root, 1);
}
```