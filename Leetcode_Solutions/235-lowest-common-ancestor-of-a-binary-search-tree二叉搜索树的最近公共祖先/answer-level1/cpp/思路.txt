### 解题思路
利用二叉搜索树的特性来做，dfs也可以做

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
    TreeNode* res;

    void help(TreeNode* root, TreeNode* p, TreeNode* q){
      if(root->left && p->val < root->val && q->val < root->val) 
        help(root->left, p, q);
      else if(root->right && p->val > root->val && q->val > root->val)
        help(root->right, p, q);
      else {
        res = root;
        return;
      }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(!root || !p || !q) return NULL;

      //help(root, p, q);
      TreeNode* cur = root;
      while(cur){
        if(p->val < cur->val && q->val < cur->val)
          cur = cur->left;
        else if(p->val > cur->val && q->val > cur->val)
          cur = cur->right;
        else
          return cur;
      }

      return cur;
    }
};
```