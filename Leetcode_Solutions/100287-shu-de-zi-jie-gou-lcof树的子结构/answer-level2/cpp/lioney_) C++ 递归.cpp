`主递归：选取A中所有的子树`
`辅助递归：递归判断A中的一个子树是否和B相同`
```
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A || !B) return false;
        if(helper(A, B)) return true;
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
    bool helper(TreeNode* A, TreeNode* B) {
        if(!B) return true;
        if(!A || A->val != B->val) return false;
        return helper(A->left, B->left) && helper(A->right, B->right);
    }
};
```
