## 思路一：哈希表
### 代码
```c++
class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> res;
        unordered_map<string, set<string>> prefix_word_map;
        int size = words[0].size();
        for (auto &word : words) {
            for (int i = 0; i < size; ++i) {
                string prefix = word.substr(0, i);
                prefix_word_map[prefix].insert(word);
            }
        }
        vector<vector<char>> matrix(size, vector<char>(size));
        helper(0, size, matrix, prefix_word_map, res);
        return res;
    }

    void helper(int i, int size, vector<vector<char>> &matrix, unordered_map<string, set<string>> &prefix_word_map, vector<vector<string>> &res) {
        if (i == size) {            
            vector<string> tmp;
            for (int j = 0; j < size; ++j) {
                tmp.push_back(string(matrix[j].begin(), matrix[j].end()));                
            }
            res.push_back(tmp);
            return;
        }
        string prefix = string(matrix[i].begin(), matrix[i].begin() + i);
        for (string word : prefix_word_map[prefix]) {
            matrix[i][i] = word[i];
            int j = i + 1;
            for (; j < size; ++j) {
                matrix[i][j] = word[j];//填充行
                matrix[j][i] = word[j];//填充列
                if (prefix_word_map.count(string(matrix[j].begin(), matrix[j].begin() + i + 1)) == 0) break;
            }
            if (j == size) helper(i + 1, size, matrix, prefix_word_map, res);
        }
    }
};
```

## 思路二：Trie
### 代码
```c++
class Solution {
public:
    struct TrieNode {
        vector<TrieNode*> children;
        vector<int> indexs;
        TrieNode() : children(26, nullptr) { }
    };
    
    TrieNode* buildTrie(const vector<string> &words) {
        TrieNode *root = new TrieNode();
        for (int i = 0; i < words.size(); ++i) {
            TrieNode *p = root;
            for (const auto &ch : words[i]) {
                int j = ch - 'a';
                if (p->children[j] ==  nullptr) {
                    p->children[j] = new TrieNode();
                }
                p = p->children[j];
                p->indexs.push_back(i);
            }
        }
        return root;
    }

    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> res;        
        int size = words[0].size();
        TrieNode *root = buildTrie(words);
        vector<string> out(size);
        for (const auto &word : words) {
            out[0] = word;
            helper(words, root, 1, out, res);
        }
        return res;
    }

    void helper(vector<string>& words, TrieNode *root, int level, vector<string> &out, vector<vector<string>> &res) {
        if (level >= words[0].size()) {
            res.push_back(out);
            return;
        }
        string str;
        for (int i = 0; i < level; ++i) {
            str += out[i][level];
        }
        TrieNode *t = root;
        for (int i = 0; i < str.size(); ++i) {
            if (!t->children[str[i] - 'a']) return;
            t = t->children[str[i] - 'a'];
        }
        for (int idx : t->indexs) {
            out[level] = words[idx];
            helper(words, root, level + 1, out, res);
        }
    }
};
```

