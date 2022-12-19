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


struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
    if (!preorder || !preorderSize)
        return NULL;
    
    struct TreeNode* p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    p->val = preorder[0];

    int idx = 1;
    while (idx < preorderSize && preorder[idx] < preorder[0]) {
        idx++;
    }
    p->left = bstFromPreorder(preorder + 1, idx - 1);
    p->right = bstFromPreorder(preorder + idx, preorderSize - idx);
    return p;
}
```