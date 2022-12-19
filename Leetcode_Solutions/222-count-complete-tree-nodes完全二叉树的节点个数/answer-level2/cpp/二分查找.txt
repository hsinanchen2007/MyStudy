使用先序、中序、后序、层序、传统递归等方法遍历，可以完美解决，例如：
```
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root==NULL) return 0;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
```
其时间复杂度都是O(n)，且对于任何二叉树都适应。对于完全二叉树或满二叉树，O(n)的复杂度根本不能满足对算法的炽热追求。完全二叉树可以分割成若干满二叉树和完全二叉树，满二叉树直接根据层高h计算出节点为2^h-1；继续计算子树中完全二叉树节点。对任意一个子树，遍历其左子树层高left，右子树层高right，相等左子树则是满二叉树，否则右子树是满二叉树，其时间复杂度为O(logn)。需分割logn次，故总时间复杂度为O((logn)^2)。
```
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root==NULL) return 0;
        int left=0, right=0;
        for(TreeNode *l=root->left; l; ++left, l=l->left);
        for(TreeNode *r=root->right; r; ++right, r=r->left);
        if (left==right) return (1<<left)+countNodes(root->right);
        return (1<<right)+countNodes(root->left);
    }
};
```
