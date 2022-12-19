### 解题思路
1. 如果p, q分别在root的两边或者root是p或q的其中一个, 则root必定是答案.
2. 如果q, p在同一边, root = root->那一边, 回到1.

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
        while (root) {
            if (root == p or root == q) return root;
            else if ((root->val - p->val) * (root->val - q->val) < 0) return root;
            else if (root->val < p->val and root->val < q->val) root = root->right;
            else if (root->val > q->val and root->val > q->val) root = root->left;
        }
        return NULL;
    }
};
```