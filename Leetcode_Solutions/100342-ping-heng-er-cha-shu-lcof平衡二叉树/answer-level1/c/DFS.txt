执行用时 :8 ms, 在所有 C 提交中击败了92.68%的用户
内存消耗 :10.4 MB, 在所有 C 提交中击败了100.00%的用户
```
int Balanced(struct TreeNode* root,int dep)
{
    int depl=0,depr=0;
    if(root==NULL)//当根节点的左节点或者右节点为null时，此时根节点的对应的左子树或者右子树深度为0
        return 0;
    if(root->left==NULL&&root->right==NULL)//当访问到叶子节点
        return dep;
    if(root->left!=NULL)
        depl=Balanced(root->left,dep+1);//depl和depr变量记录每一条路径下的深度
    if(root->right!=NULL)
        depr=Balanced(root->right,dep+1);
    return depl>depr?depl:depr;//返回深度最大值
}
bool isBalanced(struct TreeNode* root){
    if(root==NULL)//空树的情况
        return true;
    int l=Balanced(root->left,1),r=Balanced(root->right,1);
    if(abs(l-r)>1)
        return false;
    return isBalanced(root->left)&&isBalanced(root->right);//递归使得每一个结点都满足平衡条件
}
```
