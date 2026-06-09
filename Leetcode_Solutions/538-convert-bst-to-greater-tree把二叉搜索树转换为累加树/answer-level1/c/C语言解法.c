### 解题思路
![image.png](https://pic.leetcode-cn.com/d8ec264f92169439828cffea7d1e3a372ef42ebc63f019dd7a16c7bd067b2fa9-image.png)
中序遍历，边遍历边累加

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
int g_num;

void preorder(struct TreeNode* root) {
    if(!root) {
        return;
    }
    preorder(root->right);
    g_num += root->val;
    root->val = g_num;
    preorder(root->left);
}

struct TreeNode* convertBST(struct TreeNode* root){
    g_num = 0;
    preorder(root);
    return root;
}
```