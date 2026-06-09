### 解题思路
1，将单词字典中的每个单词翻转初始化字典树
2，字符流从后往前进行查找，进行判断即可

### 代码

```cpp
class StreamChecker {
public:
    struct TrieNode {
        bool flag;
        TrieNode* next[26];
        TrieNode() : flag(false), next({NULL}) {}
    };
    TrieNode* root;
    string s;
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for (const auto& w : words) {
            auto node = root;
            for (int i = w.size() - 1; i >= 0; i--) {
                int k = w[i] - 'a';
                if (node->next[k] == NULL) {
                    node->next[k] = new TrieNode();
                }
                node = node->next[k];
            }
            node->flag = true;
        }
    }
    
    bool query(char letter) {
        s += letter;
        auto node = root;
        for (int i = s.size() - 1; i >= 0; --i) {
            int k = s[i] - 'a';
            if (node->next[k] != NULL) {
                node = node->next[k];
                if (node->flag) return true;
            } else {
                return false;
            }
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
```

![image.png](https://pic.leetcode-cn.com/3fddada8a3955db4d05356be75680480c98cf3ea929f39fcf6b66c68428f0366-image.png)

