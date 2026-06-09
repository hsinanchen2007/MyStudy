```
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if(root == NULL)
        return NULL;

    int *out = NULL;
    struct TreeNode *cur = root, *pre = NULL;
    /*
        cur用来表示当前节点，pre用来表示其前驱节点。
    */
    while(cur)
    {
        if(cur->left == NULL)
        {
            out = (int *)realloc(out, sizeof(int) * (*returnSize + 1));
            out[*returnSize] = cur->val;
            *returnSize += 1;
            cur = cur->right;
        }
        else
        {
            pre = cur->left;
            while(pre->right != NULL && pre->right != cur)
                pre = pre->right;

            if(pre->right == NULL)
            {
                out = (int *)realloc(out, sizeof(int) * (*returnSize + 1));
                out[*returnSize] = cur->val;
                *returnSize += 1;
                pre->right = cur;
                cur = cur->left;
            }
            else
            {
                pre->right = NULL;
                cur = cur->right;
            }
        }
    }
    return out;
}
```