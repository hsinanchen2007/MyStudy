```
class Solution {
public:
    /*
     核心思路：
     递归实现。
     子树有无最深叶子节点取决于该树的深度 depth。
     若 root 的左右子树深度相同，则 root 为 最近公共祖先。
     若 左右子树深度不同，假设 left_depth(左子树深度) > right_depth(右子树深度)
     则最近公共节点必在左子树上，对左子树递归求解最近公共节点即可。
     **/
    int depthOfTree(const TreeNode *root) {
        if (!root) return 0;
        return 1 + max(depthOfTree(root->left), depthOfTree(root->right));
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root) return NULL;
        int left_depth, right_depth;
        left_depth = depthOfTree(root->left);
        right_depth = depthOfTree(root->right);
        if (left_depth == right_depth) return root;
        else return left_depth > right_depth ? lcaDeepestLeaves(root->left) : lcaDeepestLeaves(root->right);
    }
};
```
