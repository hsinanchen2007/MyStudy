# 思路：(看了很多篇题解，发现没有一篇题解是关于二分法思路的，故前来补充)
由于这是一颗bst,我们可以很容易的想到：当前节点的左子树的所有节点cnt+1==k的话，说明第k小的元素即是当前节点root->val,而k>cnt+1的话说明，第K小的元素是在root节点的右儿子那边，则把k-cnt-1，继续二分即可。
所以 ，可以很明显的看出，所谓的二分是指以当前节点左子树结点cnt与第k个结点的关系进行二分，小于则在左边，大于，则在右边。
```
int numofRoot(struct TreeNode* root)
{
    if(!root) return 0;
    return 1+numofRoot(root->left)+numofRoot(root->right);
}

int kthSmallest(struct TreeNode* root, int k){
    int cnt=numofRoot(root->left);

    if(k<=cnt) return kthSmallest(root->left,k);
    else if(k>cnt+1) return kthSmallest(root->right,k-cnt-1);
    return root->val;
}
```
