### 解题思路

### 代码
![image.png](https://pic.leetcode-cn.com/d3af63ecc53b0f6e71fdddea99142aeaea398efcc69d0fb5ad39480898f95f1d-image.png)

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
    TreeNode* invertTree(TreeNode* root) {
        if(root!=NULL)
        {
            swap(root->right,root->left);
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};
```