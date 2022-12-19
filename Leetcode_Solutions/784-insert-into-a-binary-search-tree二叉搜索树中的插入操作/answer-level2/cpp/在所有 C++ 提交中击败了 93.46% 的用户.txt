### 解题思路
简单容易理解的思路

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
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        insert(val,root);
        return root;
    }
    void insert(int x,TreeNode*&t)
    {
        if (t == nullptr) //如果为空
            t = new TreeNode(x);
        else if (x < t->val)
            insert(x, t->left);
        else if (t->val < x)
            insert(x, t->right);
        else
            ;
    }
};
```