### 解题思路
代码可以写一行就一定要写一行！！！！！！！！

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
       return (p->val<=root->val&&q->val>=root->val) || (p->val>=root->val&&q->val<=root->val) ?root :p->val<root->val ?lowestCommonAncestor(root->left,p,q):lowestCommonAncestor(root->right,p,q);
    }
};
```