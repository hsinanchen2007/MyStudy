### 解题思路
C

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


int rangeSumBST(struct TreeNode* root, int L, int R){
    if(root==NULL){
        return 0;
    }
    if(root->val>R){
        return rangeSumBST(root->left,L,R);
    }else if(root->val<L){
        return rangeSumBST(root->right,L,R);
    }else{
        return root->val+rangeSumBST(root->left,L,R)+rangeSumBST(root->right,L,R);
    }

}
```