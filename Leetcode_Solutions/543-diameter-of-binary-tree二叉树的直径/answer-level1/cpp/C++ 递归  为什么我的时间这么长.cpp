### 解题思路
求大佬指点一下我的代码

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
    int a(TreeNode* root){
        if(!root)
            return 0;
        return max(a(root->left),a(root->right))+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        return max(a(root->left)+a(root->right),max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right))) ;
    }
};
```