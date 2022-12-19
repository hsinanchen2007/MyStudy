### 解题思路
直接往目标祖先查找:
1.如果一个点res的值value满足：p->val < value < q->val,即不在此点的同一侧，此点为最近公共祖先
2.如果两个点都在一侧，往该侧查找。
3.剩余情况为其中一个点为公共祖先。
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
        return root;//p,q其中之一为祖先
    }
};
```