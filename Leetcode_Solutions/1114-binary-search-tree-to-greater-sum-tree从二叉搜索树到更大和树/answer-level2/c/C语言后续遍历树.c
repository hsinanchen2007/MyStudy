采用后续遍历，先右子树，将右子树的值都计算出来再遍历根节点，再遍历左子树，将计算出来的值加到节点上
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* changeTree(struct TreeNode* root, int* value)
{
    if (root != NULL)
    {        
        changeTree(root->right,value);
        *value += root->val;
        root->val = *value;
        changeTree(root->left,value);
        
    }
    return root;
}

struct TreeNode* bstToGst(struct TreeNode* root){
    int value = 0;
    return changeTree(root, &value);
}
```

