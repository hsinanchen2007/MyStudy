### 解题思路
![image.png](https://pic.leetcode-cn.com/058f1e89960bf5c9f722781a225697926e7bc778014fbb13fd398fb8b2f9d761-image.png)
结合二叉搜索树性质
### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(p->val > root->val && q->val > root->val) {
        return lowestCommonAncestor(root->right, p, q);
    }
    if(p->val < root->val && q->val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    }
    return root;  
}
```