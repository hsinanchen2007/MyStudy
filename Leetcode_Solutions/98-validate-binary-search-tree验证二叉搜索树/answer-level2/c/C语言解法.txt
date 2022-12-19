C语言解法，有优化的嘛：
bool isValidBST(struct TreeNode* root)
{
    struct TreeNode *max = NULL, *min = NULL;

    if(root == NULL)
    {
        return 1;
    }

    if(isValidBST(root->left))
    {
        max = root->left;
        while(max != NULL && max->right != NULL)
        {
            max = max->right;
        }
    }
    else
    {
        return 0;
    }

    if(isValidBST(root->right))
    {
        min = root->right;
        while(min != NULL && min->left != NULL)
        {
            min = min->left;
        }
    }
    else
    {
        return 0;
    }

    if(max != NULL)
    {
        if(root->val <= max->val)
        {
            return 0;
        }
    }

    if(min != NULL)
    {
        if(root->val >= min->val)
        {
            return 0;
        }
    }

    return 1;
}