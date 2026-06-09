### 解题思路


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
//递归法
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;//输入[],返回true
        return compare(root,root);
    }
    bool compare(TreeNode* a,TreeNode* b)
    {
        if(a==nullptr&& b==nullptr) 
            return true;//遍历到了最后
        if(a==nullptr|| b==nullptr)
            return false;//有一个是空一个不是
        if(a->val!=b->val)
            return false;
        //如果a->val==b->val
        return compare(a->left,b->right)&&compare(a->right,b->left);
    }
};
```