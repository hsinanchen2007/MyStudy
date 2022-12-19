```
class Solution {
    //比较从当前节点a开始b是否为a的子树
    bool helper(TreeNode* a, TreeNode* b){
        if(!b) return true; //b树遍历完，返回true
        if(!a) return false; //a树遍历完，返回false
        if(a->val == b->val && helper(a->left, b->left) && helper(a->right, b->right)) //当前节点相等且b的左右子树为a的左右子树的子树
            return true;
        return false;
    }
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A || !B) return false;
        if(helper(A,B)) return true;
        //若当前节点A不是子树起始点，尝试A的左右子树
        return isSubStructure(A->left,B) || isSubStructure(A->right,B);
    }
};
```
