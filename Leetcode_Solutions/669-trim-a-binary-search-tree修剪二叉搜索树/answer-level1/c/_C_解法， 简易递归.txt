# **思路：**
1）先递归到底层，遇到null停止
2）返回时，每个结点三种情况逐个分析
3）继续返还，重复以上（2）步骤

# **代码：**
```
struct TreeNode* trimBST(struct TreeNode* root, int L, int R){
    if(root == NULL) return NULL;
    
    root->left = trimBST (root->left,L,R);
    root->right = trimBST(root->right,L,R);

    if(root->val > R)
    {return root->left;}
    else if(root-> val < L)
    {return root->right;}

    return root;
}
```
