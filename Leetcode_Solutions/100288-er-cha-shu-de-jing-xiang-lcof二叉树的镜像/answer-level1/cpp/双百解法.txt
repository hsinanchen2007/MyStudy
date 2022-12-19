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
        mirrorTreeCore(root);
        return root;
    }
    void mirrorTreeCore(TreeNode* root) //递归地交换左右节点
    {
        //递归中止条件，越过叶节点
        if(root==nullptr)
            return;
        mirrorTreeCore(root->left);
        TreeNode* pTempNode=root->left;
        mirrorTreeCore(root->right);
        root->left=root->right;
        root->right=pTempNode;
        return;
    }
};
```