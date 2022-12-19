### 解题思路
二叉搜索树特点：左子树均小于根节点值，右子树都大于根节点值
所以三种情况：
当前节点从根节点开始；
（1） 如果前节点在p q之间，直接**返回**前节点；
（2） 如果前节点小于p q， 当前节点指向其右子树，**递归**搜索；
（3） 如果前节点大于p q， 当前节点指向其左子树，**递归**搜索；

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
        if(root==NULL) return NULL;
        if(root->val>p->val&&root->val<q->val) return root;
        if(root->val>p->val&&root->val>q->val) return lowestCommonAncestor(root->left,p,q);
        if(root->val<p->val&&root->val<q->val) return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};

```