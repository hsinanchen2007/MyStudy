### 解题思路
要细心哟！！！！！！😁

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
struct TreeNode* sloveTree(int* inorder, int inStart, int inEnd, int* postorder, int postStart, int postEnd);
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize);

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    return sloveTree(inorder, 0, inorderSize, postorder, 0, postorderSize);
}

struct TreeNode* sloveTree(int* inorder, int inStart, int inEnd, int* postorder, int postStart, int postEnd) {
    if (inStart >= inEnd || postStart >= postEnd) {
        return NULL;
    }
    int i = inStart;
    while (postorder[postEnd-1] != inorder[i]) {
        i++;
    }
    struct TreeNode* node = (struct TreeNode*)calloc(sizeof(struct TreeNode), 1);
    node->val = inorder[i];
    node->left = sloveTree(inorder, inStart, i, postorder, postStart, postStart+(i-inStart));
    node->right = sloveTree(inorder, i+1, inEnd, postorder, postStart+(i-inStart), postEnd-1);
    return node;
}
```