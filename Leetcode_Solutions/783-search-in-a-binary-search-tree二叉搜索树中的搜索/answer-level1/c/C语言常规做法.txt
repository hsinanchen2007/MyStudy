由于二叉搜索树某节点的左节点的值始终小于该节点的值，右节点的值始终小于右节点的值，所以此题不用递归就可以做出。
- 方法一
迭代。
```c
struct TreeNode* searchBST(struct TreeNode* root, int val){
    while(root){
        if(val==root->val)
            return root;
        else if(val>root->val)
            root=root->right;
        else root=root->left;
    }
    return 0;
}
```
- 方法二
递归。
```c
struct TreeNode* searchBST(struct TreeNode* root, int val){
    if(root==0) return 0;
    if(val>root->val)
        return searchBST(root->right,val);
    else if(val<root->val)
        return searchBST(root->left,val);
    return root;
}
```