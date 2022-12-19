### 解题思路
思路上直接递归也可以，但是递归的过程中重复遍历了许多节点。
采用后序遍历（先递归到叶节点再操作）的方式，一边遍历一边判断是否为平衡二叉树。
tip：
注意要定义左右子树的深度，并以引用的方式传入，以便在函数内部修改。

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
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        int depth = 0;
        return isSonTreeBalanced(root,depth);
    }
    bool isSonTreeBalanced(TreeNode* root,int &depth)
    {
        if(root == NULL)
            {
                depth = 0;
                return true;
            }
        int nleft = 0;
        int nright = 0;
        if(isSonTreeBalanced(root->left,nleft) && isSonTreeBalanced(root->right,nright))
        {
            if(abs(nleft-nright)<=1)
                {
                    depth = max(nleft,nright)+1;
                    return true;
                }
        }
        return false;
    }
};
```