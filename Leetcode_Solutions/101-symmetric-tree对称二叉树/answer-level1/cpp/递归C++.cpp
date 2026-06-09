### 解题思路
root的所有左节点的左孩子和右节点的右孩子相同，左节点的右孩子和右节点的左孩子相同。

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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return CompareSymmetricTree(root->left, root->right);
    }

    bool CompareSymmetricTree(TreeNode* left, TreeNode* right){
        if(left == nullptr) return right == nullptr;
        if(right == nullptr) return left == nullptr;

        if(left->val != right ->val)    return false;
        bool ret1 = CompareSymmetricTree(left->left, right->right);
        bool ret2 = CompareSymmetricTree(left->right, right->left);
        return ret1 && ret2;
    }
};
```