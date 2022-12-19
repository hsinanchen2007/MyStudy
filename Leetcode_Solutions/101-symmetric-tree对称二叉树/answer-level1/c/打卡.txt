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

bool checkTree(struct TreeNode *left, struct TreeNode *right)
{
    if(left != NULL && right != NULL){  
            if(left->val != right->val){
            return false;
        }
        return checkTree(left->left, right->right) && checkTree(left->right, right->left);
    }
    else if(left == NULL && right == NULL){
        return true;
    }

    return false;
}

bool isSymmetric(struct TreeNode* root){
    if(root == NULL){
        return true;
    }

    return checkTree(root->left, root->right);
}
```