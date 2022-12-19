#### 对称二叉树的定义：
1.空树是对称二叉树
2.对于非空树：**左子树与右子树对称**的二叉树为对称二叉树。
#### 两颗树对称的定义是什么？
1.对于空树，只与空树是对称的
2.对于非空树L，他与另一颗非空树R对称，当且仅当**L的左子树与R的右子树对称 && L的右子树与R的左子树对称**
显然这个定义是递归的，所以根据定义可以直接写出递归代码，可以稍微合并一些判断条件使得看起来更简洁。
```
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isMirror(root->left,root->right);
    }
    bool isMirror(TreeNode * leftTree, TreeNode * rightTree){
        if(leftTree && rightTree && (leftTree->val == rightTree->val)){
            return isMirror(leftTree->left,rightTree->right) && isMirror(leftTree->right,rightTree->left);
        }else if(!leftTree && !rightTree){
            return true;
        }else{
            return false;
        }
    }
};
```
