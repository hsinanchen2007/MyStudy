### 解题思路
树的直径=l+r+1-1
左右子树高度之和 加上根节点-1

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
    int m;
    int depth(TreeNode* root){
        if(!root) return 0;
        int l=depth(root->left);
        int r=depth(root->right);
        m=max(m,l+r+1);
        return max(l,r)+1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        m=0;
        depth(root);
        return m-1;
    }
};
```