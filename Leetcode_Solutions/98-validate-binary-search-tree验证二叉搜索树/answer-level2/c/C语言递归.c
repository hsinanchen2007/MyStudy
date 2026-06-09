### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/5d7b2d26c406d47f6c93dc8575408223978787435b200b94ee9cbc88b930c591-%E6%8D%95%E8%8E%B7.PNG)
满足以下三个条件为二叉搜索树：
1. 根结点的值>右孩节点、右孩结点的左孩结点、右孩结点的左孩结点的左孩结点、右孩结点的左孩结点的左孩结点的左孩结点（右左左……）
2. 根结点的值>左孩、左孩的右孩（左右右……）
3. 左子树为二叉搜索树，右子树为二叉搜索树
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


bool isValidBST(struct TreeNode* root){
  #递归终止条件
  if(!root) return true;
  if(!root->left&&!root->right) return true;
  #递归体
  struct TreeNode*  r=root->right;
  while(r){
    if(r->val<=root->val) return false;
    r=r->left;
  }
  struct TreeNode*  l=root->left;
  while(l){
    if(l->val>=root->val) return false;
    l=l->right;
  }
  return isValidBST(root->left)&isValidBST(root->right);
}
```
###算法评价
时间复杂度O（n）
空间O（n）