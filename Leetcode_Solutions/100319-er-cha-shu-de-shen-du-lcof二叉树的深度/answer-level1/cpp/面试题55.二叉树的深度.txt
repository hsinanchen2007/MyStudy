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
    int maxDepth(TreeNode* root) {   
        if(!root)
            return 0;
        int nleft=maxDepth(root->left);
        int nright=maxDepth(root->right);
        return (nleft>nright)?(nleft+1):(nright+1);
    }
};
```