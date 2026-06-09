### 解题思路


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

int getIndexFromInorder(int val, int* inorder, int start, int end) {
    int i;
    for (i = start; i <= end; i++) {
        if (val == inorder[i]) {
            return i;
        }
    }

    return -1;
}

struct TreeNode* dfs(int* preorder, int level, int* inorder, int start, int end) {
    struct TreeNode* root;
    int index;
    if (start > end) {
        return NULL;
    }

    root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[level];
    index = getIndexFromInorder(root->val, inorder, start, end);
    if (index == -1) {
        return NULL;
    }

    root->left = dfs(preorder, level + 1, inorder, start, index-1);
    root->right = dfs(preorder, level+index-start+1, inorder, index+1, end);
    return root;    
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    return dfs(preorder, 0, inorder, 0, inorderSize-1);
}


```