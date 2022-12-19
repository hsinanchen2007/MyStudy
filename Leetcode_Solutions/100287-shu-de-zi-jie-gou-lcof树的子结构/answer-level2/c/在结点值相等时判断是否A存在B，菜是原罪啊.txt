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
//能否在A中找到B的结构
bool is_eql(struct TreeNode* A, struct TreeNode* B){
    if(B==NULL) return 1;
    if(A->val!=B->val) return 0;
    int a=1,b=1;
    if(B->left){
        if(A->left&&(A->left->val==B->left->val))
            a=is_eql(A->left,B->left);
        else a=0;
    }
    if(B->right){
        if(A->right&&(A->right->val==B->right->val))
            b=is_eql(A->right,B->right);
        else b=0;
    }
    return a&&b;
}
bool isSubStructure(struct TreeNode* A, struct TreeNode* B){
    if(B==NULL||A==NULL) return 0;
    if(A->val==B->val)
        if(is_eql(A,B)) return 1;
    return isSubStructure(A->left,B)||isSubStructure(A->right,B);
}
```