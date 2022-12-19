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
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){
    if(!t1&&!t2) return NULL;
    if(t1&&t2) t1->val += t2->val;
    if(t1&&!t2) return t1;
    if(!t1&&t2) return t2;
    t1->left = mergeTrees(t1->left,t2->left);
    t1->right = mergeTrees(t1->right,t2->right); 
    return t1;
}
```