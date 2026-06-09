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


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q == NULL){
        return true;
    }
    if(p == NULL || q== NULL) {
        return false;
    }
    if(p->val != q->val){
        return false;
    }
    // q写成p了
    // if(p->val != p->val) {
    //     return false;
    // }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
```