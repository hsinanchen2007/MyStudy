右根左（RNL）遍历二叉搜索树，即逆序。
每访问一个结点求和即可
```c
void inOrder(struct TreeNode *root, int *sum)
{
    int num;
    if (root)
    {
        inOrder(root->right, sum);
        num = root->val;
        root->val += (*sum);
        (*sum) += num;
        inOrder(root->left, sum);
    }
}

struct TreeNode* convertBST(struct TreeNode* root){
    int sum = 0;
    inOrder(root, &sum);
    return root;
}
```
