### 解题思路
此处撰写解题思路

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
    if(root == NULL){
        return NULL;
    }
    if(root -> val < p ->val && root->val < q->val){
        return lowestCommonAncestor(root->right, p ,q);
    }else if(root -> val > p ->val && root->val > q->val){
        return lowestCommonAncestor(root->left, p ,q);
    }
    return root;
    
}
```