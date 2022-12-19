### 解题思路
**先序遍历+辅助判断函数**来判断B是否是A的子树。
- 首先，helper函数用来判断b是不是以a为根节点的树的子树，从头开始判断。有两个递归边界条件，递归进行判断；
- 在isSubStructure函数中，以先序遍历来判断！先判断当前的A节点为跟的树和B相比，或者A的左子树，或者A的右子树。递归，先序遍历完成。
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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A||!B) return false;
        return helper(A,B)||isSubStructure(A->left,B)||isSubStructure(A->right,B); //先序遍历
    }

    bool helper(TreeNode* a,TreeNode *b){
        if(!b)  return true;
        if(!a||a->val!=b->val)  return false;
        return helper(a->left,b->left)&&helper(a->right,b->right);
    }
};
```