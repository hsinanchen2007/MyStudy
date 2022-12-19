### 解题思路
此处撰写解题思路
如果当前值在p q之间返回当前值
当前值比p 小 向右边查找
当前值比q 大 向左边查找
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if((root->val-p->val)*(root->val-q->val)<=0)
            return root;
        if(root->val<p->val)
            return lowestCommonAncestor(root->right,p,q);
        if(root->val>q->val)
            return lowestCommonAncestor(root->left,p,q);
        return NULL;
    }
};
```