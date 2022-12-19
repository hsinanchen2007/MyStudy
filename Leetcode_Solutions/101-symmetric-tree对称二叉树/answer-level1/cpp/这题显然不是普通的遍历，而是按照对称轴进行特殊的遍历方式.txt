### 解题思路
思路写在代码注释里
不过这题踩了一坑：空树也是对称的（做题做习惯了，直接return false）

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
//这题并不是判断左右子树是否完全一样，而是判断是否对称
    bool isSymmetric(TreeNode* root) {
        //空树是对称的
        if(root == NULL) return true;
        //要先判断，不然对任何类型空指针进行成员访问都是违法的
        return isSymmetric(root->left,root->right);
    }
    bool isSymmetric(TreeNode* t1,TreeNode* t2){
        if(t1 == NULL && t2 == NULL) return true;
        if(t1 == NULL || t2 == NULL) return false;
        if(t1->val != t2->val) return false;
        //判断筛选出来的就是值相等的，这时候还要继续判断
        //第一个形参的左子树，和第二个形参的右子树是否对称
        //以及第一个的右子树和第二个的左子树是否对称
        return isSymmetric(t1->left,t2->right) && isSymmetric(t1->right,t2->left);
    }
};
```