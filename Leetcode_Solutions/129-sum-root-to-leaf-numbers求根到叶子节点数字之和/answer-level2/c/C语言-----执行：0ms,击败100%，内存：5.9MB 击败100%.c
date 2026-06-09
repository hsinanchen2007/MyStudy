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
void SearchSum(struct TreeNode*root,int*add,int sum){
    if(!root)  return;
    if(root->left==NULL&&root->right==NULL){
        *add=*add+(sum*10+root->val);
    }
    else{
        sum=sum*10+root->val;
    }
    SearchSum(root->left,add,sum);
    SearchSum(root->right,add,sum);
}
int sumNumbers(struct TreeNode* root){
int add=0,sum=0;
SearchSum(root,&add,sum);
return add;
}
```