### 解题思路
此处撰写解题思路

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
int treeHigh1(TreeNode *root){
    if (root==NULL) return 0;
    int left_high=treeHigh1(root->left);
    int right_high=treeHigh1(root->right);
    return (left_high>right_high?left_high+1:right_high+1);
}
    bool isBalanced(TreeNode *root) {
    if (!root) return true;
    if (fabs(treeHigh1(root->left)-treeHigh1(root->right))>1) {
        return false;
    }
    return isBalanced(root->left)&&isBalanced(root->right);
}
};
```