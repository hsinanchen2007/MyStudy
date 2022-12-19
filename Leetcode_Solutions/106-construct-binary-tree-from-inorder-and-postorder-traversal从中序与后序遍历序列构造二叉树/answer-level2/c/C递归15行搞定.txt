### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/abc1bfe6ffd5254f9231c1b7055e9ae2dd13963df12f099b74d5875233f6c233-%E6%8D%95%E8%8E%B7.PNG)


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


struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    if (inorder == NULL || inorderSize == 0) {
        return NULL;
    }
    struct TreeNode *res = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    res->val = postorder[postorderSize - 1];
    int idx = -1;
    for (int i = 0; i < inorderSize; i++) {
        if (res->val == inorder[i]) {
            idx = i;
            break;
        }
    }
    res->left = buildTree(inorder, idx, postorder, idx);
    res->right = buildTree(inorder+1+idx, inorderSize-idx-1, postorder+idx, inorderSize-idx-1);
    return res;
}
```