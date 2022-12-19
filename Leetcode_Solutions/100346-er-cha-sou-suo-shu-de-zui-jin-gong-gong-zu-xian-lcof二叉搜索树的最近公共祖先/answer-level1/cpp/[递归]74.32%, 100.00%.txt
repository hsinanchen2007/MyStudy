### 解题思路
当root在两节点之间找到，push到叶子还没找，木有就实锤了

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
    TreeNode* lowestCommonAncestor(TreeNode* &root, TreeNode* &p, TreeNode* &q) {
        // complete srch
        // O(logN), O(logN)
        // def dfs -> node:
        //     if (p || q < root->val < q || p)
        //         return root;
        //     else if (p, q < root->val)
        //         l0 = dfs(root->l);
        //         l1 = dfs(root->l);
        //     else  
        //         return l0 = dfs(root->l);
        //         r1 = dfs(root->r);
        //         r2 = dfs(root->r);
        if (root == NULL)
            return NULL;        
        // if (root->val >= p->val && root->val <= q->val
        //     || root->val >= q->val && root->val <= p->val)
        //     return root;
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);        
        if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
```