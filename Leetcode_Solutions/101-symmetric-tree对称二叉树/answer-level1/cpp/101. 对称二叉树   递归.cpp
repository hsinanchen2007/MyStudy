return r1->val==r2->val&&issy(r1->left,r2->right)&&issy(r1->right,r2->left);

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
  bool  issy(TreeNode* r1,TreeNode* r2){
      if(!r1&&!r2) return true;
      if(!r1||!r2) return false;
      return r1->val==r2->val&&issy(r1->left,r2->right)&&issy(r1->right,r2->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return issy(root->left,root->right);
    }
};
```