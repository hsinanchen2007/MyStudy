### 解题思路

首先想到应该可以是使用递归的方式来解决问题的，于是采用原本的函数`maxDepth`，也因此，就写了三行代码。。。

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
        if(root == NULL)
            return 0;

        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};
```