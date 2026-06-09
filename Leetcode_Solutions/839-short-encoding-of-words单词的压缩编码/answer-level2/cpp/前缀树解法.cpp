首先需要反转单词，然后构建前缀树，最后的结果就是叶子节点的深度和再加上叶子节点的个数(#)。

```
typedef struct TrieNode {
    TrieNode* next[26] = {NULL};
    TrieNode() {}
} * Trie;

class Solution {
   public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie trie = buildTrie(words);
        dfs(trie, 0);
        return res;
    }

   private:
    void dfs(Trie trie, int depth) {
        if (!trie) return;

        // 遍历子节点
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (trie->next[i] != NULL) {
                count++;
                dfs(trie->next[i], depth + 1);
            }
        }

        // 如果是叶子节点
        if (count == 0) {
            res += depth + 1; // depth代表能组合的单词的总长度，#占用一个字符长度，所以最后+1
            return;
        }
    }

    Trie buildTrie(vector<string>& words) {
        Trie trie = new TrieNode();
        for (string str : words) {
            Trie p = trie;
            for (int i = str.size() - 1; i >= 0; i--) {
                int idx = str[i] - 'a';
                if (!p->next[idx]) p->next[idx] = new TrieNode();
                p = p->next[idx];
            }
        }
        return trie;
    }

    int res = 0;
};

```
