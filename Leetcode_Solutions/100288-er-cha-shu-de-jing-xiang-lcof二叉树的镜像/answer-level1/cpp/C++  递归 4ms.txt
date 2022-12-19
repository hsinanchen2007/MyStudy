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
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        TreeNode* p = root -> left;
        root -> left = root -> right;
        root -> right = p;
        mirrorTree(root -> left);
        mirrorTree(root -> right);
        return root;
    }
};
```