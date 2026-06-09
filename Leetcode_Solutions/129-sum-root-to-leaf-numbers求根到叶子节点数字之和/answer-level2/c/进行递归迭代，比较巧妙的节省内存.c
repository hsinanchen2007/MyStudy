```
void sum_tree(struct TreeNode *root, int value_root, int *count)
{
    if (root->right == NULL && root->left == NULL)
    {
        *count += value_root;
        return ;
    }
    else if (root->right == NULL)
    {
        sum_tree(root->left, value_root * 10 + root->left->val, count);
    }
    else if (root->left == NULL)
    {
        sum_tree(root->right, value_root * 10 + root->right->val, count);
    }
    else
    {
        sum_tree(root->left, value_root * 10 + root->left->val, count);
        sum_tree(root->right, value_root * 10 + root->right->val, count);
    }
}

int sumNumbers(struct TreeNode* root){
    int count = 0;
    if (!root)
        return 0;
    else
    {
        sum_tree(root, root->val, &count);
    }
    return count;
}
```
