### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int x,int y){
    if(x>y)
    return x;
    return y;
}
int max_sum(struct TreeNode*p,int*ans){
    if(!p)   return 0;
    int left=max_sum(p->left,ans);
    int right=max_sum(p->right,ans);
    *ans=max(*ans,p->val);
    *ans=max(*ans,p->val+left);
    *ans=max(*ans,p->val+right);
    *ans=max(*ans,p->val+left+right);
    if(left<=0&&right<=0)
    return p->val;
    else
    return (left>right)?left+p->val:right+p->val;
}
int maxPathSum(struct TreeNode* root){
int ans=root->val;
max_sum(root,&ans);
return ans;
}
```