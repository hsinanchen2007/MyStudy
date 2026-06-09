### 解题思路
二叉树的解法大部分都是和递归是有关系的。
我们可以通过递归来求解。

左边的树，节点为l1，右边的树，节点为l2；
列出本题的关系：
l1->val   = l1->val + l2->val;
l1->left  = l1->left + l2->left;
l1->right = l1->right + l2->right;
这样的话，递归就很好写了。

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL) return t2;
        if(t2 == NULL) return t1;
        t1->val = t1->val + t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};
```