执行用时 :0 ms, 在所有 C 提交中击败了100.00% 的用户
内存消耗 :7.2 MB, 在所有 C 提交中击败了100.00%的用户
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode Node;
void _invertTree(struct TreeNode* root)
{
  if(root->left==NULL && root->right==NULL)
    return;
  if(root->left!=NULL && root->right==NULL)
    _invertTree(root->left);  
  if(root->left==NULL && root->right!=NULL)
    _invertTree(root->right);

  if(root->left!=NULL && root->right!=NULL)
  {
        _invertTree(root->right);
        _invertTree(root->left);
  }
  Node* temp=root->left;
  root->left=root->right;
  root->right=temp;
}
struct TreeNode* invertTree(struct TreeNode* root)
{
  if(root==NULL)
    return NULL;
  if(root->left==NULL && root->right==NULL)
    return root;
  
  if(root->left==NULL && root->right!=NULL)
    _invertTree(root->right);

  
  if(root->right==NULL && root->left!=NULL)
    _invertTree(root->left); 
  
  if(root->left!=NULL && root->right!=NULL)
  {
    _invertTree(root->right);
    _invertTree(root->left);
  } 
  Node* temp=root->left;
  root->left=root->right;
  root->right=temp;
  
  return root;
}
```
