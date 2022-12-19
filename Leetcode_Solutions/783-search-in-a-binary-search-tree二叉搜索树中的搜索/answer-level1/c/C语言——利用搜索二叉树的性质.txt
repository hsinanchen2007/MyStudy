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


struct TreeNode* searchBST(struct TreeNode* root, int val){
    if(root == NULL)
        return NULL;
    if(root->val == val)
        return root;
    else if(root->val > val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}


```