### 解题思路
递归解决。
记得保存！不然交换时会乱掉！

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
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==NULL)  return NULL;
        TreeNode *temp=root->left;
        root->left=mirrorTree(root->right);
        root->right=mirrorTree(temp);
        return root;
    }
};
```