```
struct TreeNode* invertTree(struct TreeNode* root){
    if(root==NULL)
        return NULL; 
    invertTree(root->left);
    invertTree(root->right);
    struct TreeNode* temp;//交换的这个步骤，可以换位置，分别为前中后序
    temp=root->left;
    root->left=root->right;
    root->right=temp;
    return root;
}
```
