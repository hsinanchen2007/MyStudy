### 解题思路
思路很清晰，和这道题是一个性质的。[二叉树中的列表](https://leetcode-cn.com/problems/linked-list-in-binary-tree/)

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

bool isOK(struct TreeNode *t1,struct TreeNode *t2)
{
    if(!t1&&!t2)return true;
    if(!t1||!t2)return false;
    if(t1->val==t2->val)return isOK(t1->right,t1->right)&&isOK(t1->left,t2->left);
    return false;
}
bool checkSubTree(struct TreeNode* t1, struct TreeNode* t2){
    if(!t1&&!t2)return true;
    if(!t1||!t2)return false;
    return isOK(t1,t2)||checkSubTree(t1->right,t2)||checkSubTree(t1->left,t2);
}
```