
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* last = NULL;

void treeToList(struct TreeNode* root) {
    if(root == NULL) return;

    if (last != NULL) {
        last->left = NULL;
        last->right = root;
    }
    
    last = root;
    struct TreeNode* tmpRight = root->right;
    treeToList(root->left);
    treeToList(tmpRight);
    return;
}

void flatten(struct TreeNode* root) {
    last = NULL;
    treeToList(root);
}


```
