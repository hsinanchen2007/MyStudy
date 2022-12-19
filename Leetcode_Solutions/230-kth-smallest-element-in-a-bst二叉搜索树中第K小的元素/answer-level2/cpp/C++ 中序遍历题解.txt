### 解题思路
利用find记录是否找到结果，来提前终止遍历过程

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root,int& res, bool& find, int& i, int k) {
        if (root == NULL || find) return;
        dfs(root->left, res, find, i, k);
        if (++i == k) {
            res = root->val;
            find = true;
            return;
        }
        dfs(root->right, res, find, i, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        bool find = false;
        int res = -1;
        int i = 0;
        dfs(root, res, find, i, k);
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/18ebd58549c5da2420e3e36f926fad5dfd29c71d0fd0b1af988e6f088b8d991b-image.png)
