```
class Solution {
public:
    struct TreeNode {
        int len;
        map<char, TreeNode*> next;
        TreeNode() : len(0) {};
    };
    TreeNode* root;
    Solution() {
        root = new TreeNode();
    }
    int minimumLengthEncoding(vector<string>& words) {
        int res = 0;
        for (auto& w : words) {
            auto node = root;
            for (int i = w.size() - 1; i >= 0; --i) {
                char c = w[i];
                if (node->next.count(c) == 0) {
                    node->next[c] = new TreeNode();
                }
                node = node->next[c];
                if (node->len > 0) {
                    res -= node->len;
                    node->len = 0;
                }
            }
            if (node->len == 0 && node->next.empty()) {
                node->len = 1 + w.size();
                res += node->len;
            }
        }
        return res;
    }
};
```


![image.png](https://pic.leetcode-cn.com/ad42d7ab438e571abe0608043b6548c318c6ab9d949fdcec6c67f941fd27fda2-image.png)
