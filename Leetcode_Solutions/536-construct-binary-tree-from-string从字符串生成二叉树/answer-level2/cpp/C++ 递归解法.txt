```C++ []
class Solution {
public:
    TreeNode* dfs(const string& s, int l, int r) {
        if (l > r) return NULL;
        int i = l;
        while (i <= r && s[i] != '(') ++i;
        TreeNode* res = new TreeNode(stoi(s.substr(l, i - l)));
        while (i <= r) {
            int j = i;
            int c = 1;
            while (c > 0 && ++j <= r) c += (s[j] == '(') - (s[j] == ')');
            auto node = dfs(s, i + 1, j - 1);
            if (res->left == NULL) res->left = node;
            else res->right = node;
            i = j + 1;
        }
        return res;
    }
    TreeNode* str2tree(string s) {
        return dfs(s, 0, s.size() - 1);
    }
};
```

![image.png](https://pic.leetcode-cn.com/7de986d30ad711266445bb4f3d570580a76f27cc28f341d4c318c83c3ba1f8e2-image.png)
