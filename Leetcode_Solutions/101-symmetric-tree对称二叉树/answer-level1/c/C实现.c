### 解题思路

### 代码

```c
bool Symmetric(struct TreeNode* left , struct TreeNode* right)
{
    if(left == NULL && right == NULL)
    {
        return true;
    }
    if(left == NULL || right == NULL)
    {
        return false;
    }
    if(Symmetric(left->left,right->right))
    {
        if(Symmetric(left->right,right->left))
        {
            if(left->val == right->val)
            {
                return true;
            }
        }
    }
    return false;
}

bool isSymmetric(struct TreeNode* root){
    if(root == NULL)
    {
        return true;
    }
    return Symmetric(root->left,root->right);
}
```