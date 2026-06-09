```

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/* 中序遍历二叉树 */
int inVisitBiTree(struct TreeNode* root, int *pOut, int* returnSize)
{
    if(root)
    {
        /* 遍历左子树 */
        inVisitBiTree(root->left, pOut, returnSize);


        /* 先遍历根节点 */
        //printf("%d %d \n",root->val, *returnSize);
        *(pOut + (*returnSize)) = root->val;
        (*returnSize)++;

        /* 遍历右子树 */
        inVisitBiTree(root->right, pOut, returnSize);

    }
    return 0;
}

/*
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *pOut;

    pOut = (int *)malloc(101 * sizeof(int));
    *returnSize = 0;

    (void)inVisitBiTree(root, pOut, returnSize);

    return pOut;
}

```