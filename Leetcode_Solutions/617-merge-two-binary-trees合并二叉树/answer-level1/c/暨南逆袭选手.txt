### 解题思路
将t2合并到t1。

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


struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){
    if( t1 == NULL && t2 == NULL ) return NULL;
    if( t1 == NULL ) return t2;
    if( t2 == NULL ) return t1;
    if( t1 != NULL && t2 != NULL ) {
        t1->val += t2->val;
        // merge left tree
        if( t1->left != NULL && t2->left != NULL ) {
            mergeTrees(t1->left, t2->left);
        }
        else if( t1->left == NULL && t2->left != NULL ) {
            t1->left = t2->left;
        }
        // merge right tree
        if( t1->right != NULL && t2->right != NULL ) {
            mergeTrees(t1->right, t2->right);
        }
        else if( t1->right == NULL && t2->right != NULL ) {
            t1->right = t2->right;
        }
    }
    return t1;
}
```