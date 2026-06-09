### 解题思路
先序遍历的模板
一个树是另一个树的子树，则：
1.要么这两个树相等
2.要么这个树是左树的子树
3.要么这个树是右树的子树
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL) 
        {
            return false;
        }
        //判断是否相同
        if(isSame(s, t))
        {
            return true;
        }
        return isSubtree(s->left, t)||isSubtree(s->right, t);
    }
    
    //判断两个数是否相同
    bool isSame(TreeNode* s, TreeNode* t) 
    {
        if(s == NULL && t == NULL) 
        {
            return true;
        }
        if(s == NULL || t == NULL) 
        {
            return false;
        }

        if(s->val != t->val) 
        {
            return false;
        }
        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }

};
```