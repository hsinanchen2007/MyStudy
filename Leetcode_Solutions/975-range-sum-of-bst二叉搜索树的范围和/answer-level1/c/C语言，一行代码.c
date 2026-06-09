### 解题思路
题目描述能否再清楚一点点，我语文不好

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
    return (root) ? ( (root->val < L || root->val > R) ? (rangeSumBST(root->left,L,R) + rangeSumBST(root->right,L,R)) : (root->val + rangeSumBST(root->left,L,R) + rangeSumBST(root->right,L,R)) ) : 0;
}
```