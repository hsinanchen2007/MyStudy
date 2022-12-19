### 解题思路
后序遍历递归

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


int minDepth(struct TreeNode* root){
        if(root==NULL)return 0;
        if(root->left==NULL&&root->right==NULL)return 1;
        int l=0,r=0;
        if(root->left)l=minDepth(root->left);
        if(root->right)r=minDepth(root->right);
        if(l==0)return (r+1);
        if(r==0)return (l+1);
        int k=(l<r?l:r)+1;
        return k;
}
```