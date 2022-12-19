### 解题思路
虽然是dfs，但是return条件还是需要仔细想想的，有一点难度

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
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(!root) return NULL;

      if(root == p || root == q)  return root;

      TreeNode* left = dfs(root->left, p, q);
      TreeNode* right = dfs(root->right, p, q);

      if(left && right) return root;
      else if(left) return left;
      else return right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(!root || !p || !q) return NULL;

      return dfs(root, p, q);
    }
};
```