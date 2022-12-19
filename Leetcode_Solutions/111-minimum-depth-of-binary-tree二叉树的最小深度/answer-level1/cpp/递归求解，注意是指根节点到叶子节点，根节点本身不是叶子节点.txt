### 解题思路
递归求解，注意是指根节点到叶子节点，根节点本身不是叶子节点

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
        if(root==NULL)
            return 0;
        else
            if(root->left!=NULL&&root->right!=NULL)
                return 1+min(minDepth(root->left),minDepth(root->right));
            else
                if(root->left!=NULL)
                    return 1+minDepth(root->left);
                else
                    return 1+minDepth(root->right);
    }
};
```