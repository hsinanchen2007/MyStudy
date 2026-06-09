### 解题思路
纯C 递归

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
    if (NULL == t1)
    {
        return t2;
    }

    if (NULL == t2)
    {
        return t1;
    }

    struct TreeNode* pRoot = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    pRoot->val = t1->val + t2->val;

    pRoot->left = mergeTrees(t1->left, t2->left);
    pRoot->right = mergeTrees(t1->right, t2->right);

    return pRoot;
}
```