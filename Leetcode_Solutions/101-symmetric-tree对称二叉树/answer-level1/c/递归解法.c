### 解题思路
把它想象成两个树，两个同时进行遍历，一个用“根节点->左节点->右节点”，一个用“根节点->右节点->左节点”的遍历顺序同时进行遍历比较

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
bool search(struct TreeNode* root1 ,struct TreeNode* root2)
{
    if(root1==NULL  &&root2==NULL)
      return true;
    if(root1==NULL ||root2==NULL)
      return false;
    if(root1->val!=root2->val)
      return false;
    return  search(root1->left,root2->right) &&search(root1->right,root2->left);
}

bool isSymmetric(struct TreeNode* root)
{
    if(root==NULL)
      return true;
    return search(root,root);
}
```