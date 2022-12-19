### 解题思路
先序遍历递归

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
int dfs(struct TreeNode* root,int key){
    if(root->val>key)return root->val;
    if(!root->left&&!root->right)return -1;
    int l,r,n;
    if(root->left)l=dfs(root->left,key);
    if(root->right) r=dfs(root->right,key);
    if(l==-1&&r==-1)return -1;
    if(l==-1)return r;
    if(r==-1)return l;
    n=l<r?l:r;
    return n;
}

int findSecondMinimumValue(struct TreeNode* root){
        if(!root->left&&!root->right)return -1;
        //从根节点开始递归
        return dfs(root,root->val);
        
}
```