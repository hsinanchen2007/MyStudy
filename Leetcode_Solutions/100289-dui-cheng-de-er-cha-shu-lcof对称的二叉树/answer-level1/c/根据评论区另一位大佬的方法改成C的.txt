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
}
*/

bool recur(struct TreeNode* left,struct TreeNode* right){
    if(left==NULL&&right==NULL) return true;
    if(left==NULL||right==NULL||left->val!=right->val) return false;
    return recur(left->left,right->right)&&recur(left->right,right->left);
}
bool isSymmetric(struct TreeNode* root){
    return root==NULL?true:recur(root->left,root->right);
}


```