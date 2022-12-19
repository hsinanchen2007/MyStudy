### 解题思路
递归 中序遍历

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
void traverse(struct TreeNode* pNode, struct TreeNode** ppPrev, struct TreeNode** ppErr1, struct TreeNode** ppErr2)
{
    if (pNode->left)
    {
        traverse(pNode->left, ppPrev, ppErr1, ppErr2);
    }

    if (*ppPrev && pNode->val < (*ppPrev)->val)
    {
        *ppErr1 = (*ppErr1 == NULL) ? *ppPrev : *ppErr1;
        *ppErr2 = pNode;
    }
    *ppPrev = pNode;

    if (pNode->right)
    {
        traverse(pNode->right, ppPrev, ppErr1, ppErr2);
    }
}

void recoverTree(struct TreeNode* root){
    if (!root)
    {
        return;
    }

    struct TreeNode* pPrev = NULL;
    struct TreeNode* pErr1 = NULL;
    struct TreeNode* pErr2 = NULL;
    int temp = 0;
    
    traverse(root, &pPrev, &pErr1, &pErr2);
    
    temp = pErr1->val;
    pErr1->val = pErr2->val;
    pErr2->val = temp;
}
```