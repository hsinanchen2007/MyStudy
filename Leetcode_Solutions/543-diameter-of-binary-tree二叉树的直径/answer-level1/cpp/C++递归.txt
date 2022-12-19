直接递归，每次返回左右子树高度最大值，并在返回之前更新路径最大值，不然就出问题咯。例如：直接递归思路
```
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return leftDepth+rightDepth;
    }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
};
```
上述没有考虑`[4,-7,-3,null,null,-9,-3,9,-7,-4,null,6,null,-6,-6,null,null,0,6,5,null,9,null,null,-1,-4,null,null,null,-2]`，不一定过根节点。。。所以不能按照上述来，而是递归放在子树中去比较大小。

```cpp
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int res=0;
        helper(root,res);
        return res; 
    }
    int helper(TreeNode* root,int& res) {
        if(!root) return 0;
        int lRes = root->left ? helper(root->left,res) + 1 : 0;
        int rRes = root->right ? helper(root->right,res) + 1: 0;
        res =  max(res,lRes+rRes);
        return max(lRes,rRes);
    }
};
```