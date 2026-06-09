### 解题思路
![Snipaste_2020-03-16_14-37-17.png](https://pic.leetcode-cn.com/5b82ecea05c5f036510c9d545b7c2b4522736d71f0f433103b7f1e2343eeeea7-Snipaste_2020-03-16_14-37-17.png)
1.若为单节点则真
2.若只有单叉则判断根结点值与子树根结点值是否相等，如相等则向下递归
3.若为双叉则三个节点（根结点、根的左孩子和右孩子）是否相等，如相等则分别递归

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


bool isUnivalTree(struct TreeNode* root){
    if(root->left==NULL&&root->right==NULL){
        return true;
    }else if(root->right==NULL){
        if(root->val==root->left->val){
            return isUnivalTree(root->left);
        }else{
            return false;
        }
    }else if(root->left==NULL){
        if(root->val==root->right->val){
            return isUnivalTree(root->right);
        }else{
            return false;
        }
    }else{
        if(root->val==root->left->val&&root->val==root->right->val){
            return isUnivalTree(root->left)&&isUnivalTree(root->right);
        }else{
            return false;
        }
    }
}
```