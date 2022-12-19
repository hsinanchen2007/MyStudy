### 解题思路
利用递归和二叉搜索树的特点！
- 如果，p和q的值,一个比当前root大，一个比当前root校，（即从这里要分道扬镳了，所有这里就是公共祖先）
- 如果都比root小，那么去左子树找
- 如果都比root大，那么去右子树找

所以说，核心思想就是，找到第一个使得p和q的值分道扬镳的就是最近公共祖先。
利用递归往下找。

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
      if((root->val-p->val)*(root->val-q->val)<=0){
          return root;
      }  
      if(q->val<root->val){
          return lowestCommonAncestor(root->left,p,q);
      }
      if(q->val>root->val){
          return lowestCommonAncestor(root->right,p,q);
      }
      return NULL;

    }
};
```