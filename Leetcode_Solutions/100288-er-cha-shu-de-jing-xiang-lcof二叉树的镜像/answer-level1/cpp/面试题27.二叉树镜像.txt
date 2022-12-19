### 解题思路
用递归的方法

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
    TreeNode* mirrorTree(TreeNode* node) {
        if(!node)
            return NULL;
        if(!node->left&&!node->right)
            return node;
        TreeNode *temp=node->left;
        node->left=node->right;
        node->right=temp;

        if(node->left)
        {
            mirrorTree(node->left);
        }
        if(node->right)
        {
            mirrorTree(node->right);
        }
        return node;
    }
};
```