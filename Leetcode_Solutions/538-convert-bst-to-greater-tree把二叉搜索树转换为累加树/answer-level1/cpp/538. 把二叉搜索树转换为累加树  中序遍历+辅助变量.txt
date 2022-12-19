### 解题思路
因为空节点root-》val非法，所以要加个辅助变量

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
       int temp=0;
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL) return root;
        convertBST(root->right);
        temp+= root->val;
        root->val=temp;
        convertBST(root->left);
        return root;
    }
};
```