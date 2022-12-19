### 代码

```cpp
class Solution {
public:
    struct TrieNode {
        bool flag;
        vector<TrieNode*> next;
        TrieNode() : flag(false), next(26, NULL) {};
    };
    TrieNode* root;
    Solution() {
        root = new TrieNode;
    }
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        string res;
        for (auto w : words) {
            auto node = root;
            bool valid = true;
            for (int i = 0; i < w.size(); ++i) {
                if (node->next[w[i] - 'a'] == NULL) {
                    node->next[w[i] - 'a'] = new TrieNode;
                }
                node = node->next[w[i] - 'a'];
                if (i < w.size() - 1 && !node->flag) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                node->flag = true;
                if (w.size() > res.size()) {
                    res = w;
                }
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/c17280ad0fae126a9d4447889dfc0bd749d5cfefc5e0409f45be1a3c42e8dae9-image.png)
