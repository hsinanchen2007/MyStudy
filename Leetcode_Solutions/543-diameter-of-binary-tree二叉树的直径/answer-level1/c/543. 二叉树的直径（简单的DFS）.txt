![image.png](https://pic.leetcode-cn.com/ad3237b9fb98657e80d5aa16128a9d9fb52d8d07f0f6253a41dc5f47d730b20a-image.png)

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxdeep;
int dfs(struct TreeNode* r){
    if(r==NULL)return 0;//节点为空
    if(r->left==NULL&&r->right==NULL)return 0;//节点左右子树为空
    int max=0,tmp;
    if(r->left!=NULL){//查找左子树最大深度，其中max用来表示当前根节点到叶子节点的最大深度，r->val存放着左子树的最大深度+右子树的最大深度，也就是经过当前根节点的最大直径
        r->val=dfs(r->left)+1;
        if(max<r->val)
            max=r->val;
    }else{
        r->val=0;
    }
    if(r->right!=NULL){
        tmp=dfs(r->right)+1;
        r->val+=tmp;
         if(max<tmp)
            max=tmp;
    }
    if(maxdeep<r->val)maxdeep=r->val;//计算出val之后我们只需要计算经过每个节点的最大值
    return max;
}

int diameterOfBinaryTree(struct TreeNode* root){
    maxdeep=0;
    dfs(root);
    return maxdeep;
}
```
