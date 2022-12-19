*判断一棵树是否为对称的二叉树。*
空树和左右子树为空的树都是对称二叉树；
对于一般的二叉树，判断当前节点的左节点元素是否等于当前节点的右节点元素：
    1.如果相等，继续判断该节点的左右子树是否为对称的；
    2.如果不相等，直接返回false;

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
    bool isSymmetric(TreeNode* root1,TreeNode* root2)
    {
        if(!root1 && !root2)
            return true;
        if( (!root1 && root2) || (root1 && !root2) || (root1->val != root2->val))
            return false;
        return isSymmetric(root1->left,root2->right) && isSymmetric(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr || (root->left==nullptr && root->right==nullptr))
            return true;
        return isSymmetric(root,root);
    }
};
```