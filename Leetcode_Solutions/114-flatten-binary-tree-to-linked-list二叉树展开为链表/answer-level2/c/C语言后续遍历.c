
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root)
{
    if (root == NULL) {
        return;
    }

    flatten(root->left);
    flatten(root->right);

    //后续遍历，把左节点插入到根节点与右节点中间，左节点置空
    struct TreeNode* temp = root->right;
    root->right = root->left;
    root->left = NULL;

    //左节点可能存在已经排序好的一串右节点，遍历到最后一个，接上右节点
    while (root->right != NULL) {
        root = root->right;
    }
    root->right = temp;

    return;
}
```

