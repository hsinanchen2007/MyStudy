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
void dfs(struct TreeNode* root,int s,int *ans){
    if(!root->left&&!root->right){
        s=s*10+root->val;
        *ans+=s;
    }
    else{
        s=s*10+root->val;
        if(root->left) dfs(root->left,s,ans);
        if(root->right) dfs(root->right,s,ans);
    }
}
int sumNumbers(struct TreeNode* root){
    if(root==NULL) return 0;
    if(!root->left&&!root->right) return root->val;
    int *ans;
    ans=(int*)malloc(sizeof(int));
    *ans=0;
    dfs(root,0,ans);
    return *ans;
}
```