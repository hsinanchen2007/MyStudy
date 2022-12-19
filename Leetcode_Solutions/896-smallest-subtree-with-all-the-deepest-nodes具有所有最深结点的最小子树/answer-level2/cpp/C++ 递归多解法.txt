# 解法一：
借助计算树深度来求解本题
```
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
    int depth(TreeNode* root) {
        if (root == NULL) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (root == NULL) return root;
        int dl = depth(root->left);
        int dr = depth(root->right);
        if (dl == dr) return root;
        if (dl > dr) return subtreeWithAllDeepest(root->left);
        return subtreeWithAllDeepest(root->right);
    }
};
```

![image.png](https://pic.leetcode-cn.com/c0be9209264c9b3f3b75a37f030c1fa676edc05706dae512a4820b86d69e151f-image.png)

# 解法二：
直接递归求解
```
class Solution {
public:
    pair<int, TreeNode*> dfs(TreeNode* root, int d) {
        if (root == NULL) return {-1, root};
        if (root->left == NULL && root->right == NULL) return {d, root};
        auto pl = dfs(root->left, d + 1);
        auto pr = dfs(root->right, d + 1);
        if (pl.first < pr.first) return pr;
        if (pl.first > pr.first) return pl;
        return {pl.first, root};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root, 0).second;
    }
};
```

![image.png](https://pic.leetcode-cn.com/f2e46b71aeed4f40fe1c4b1f2b9f719393af98faf214a2051e691b69ed1492d6-image.png)

