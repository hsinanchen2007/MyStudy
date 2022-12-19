### 解题思路
想明白递归就可以

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
    int minDepth(TreeNode* root) {
        if(root == NULL)return 0;  
        int l = minDepth(root->left) + 1;
        int r = minDepth(root->right) + 1;
        if(root->left == NULL)return r;
        if(root->right == NULL)return l;
        return min(l, r);
    }
};
```