### 解题思路
此处撰写解题思路

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
    TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val>q->val) return lowestCommonAncestor(root,q,p);   //默认q的值大于p的值
        if(root->val>q->val) lowestCommonAncestor(root->left,p,q);   //p和q在root的左子树里面
        else if(root->val<p->val) lowestCommonAncestor(root->right,p,q); //p和q在root的右子树里面
        else ans=root;                      //p在root的左子树里面，q在root的右子树里面，此时答案就是root;
        return ans;
    }
};
```