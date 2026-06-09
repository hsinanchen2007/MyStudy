### 解题思路
这道题很简单 就是找root->val>=p->val&&root->val<=q->val或者root->val>=q->val&&root->val<=p->val

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
        if(!root||(!root->left&&!root->right)) return root;
        while(root){
            if(p->val<q->val){
                if(root->val>=p->val&&root->val<=q->val) return root;
                if(root->val>q->val) root = root->left;
                if(root->val<p->val) root = root->right;
            }
            else{
                if(root->val>=q->val&&root->val<=p->val) return root;
                if(root->val>p->val) root = root->left;
                if(root->val<q->val) root = root->right;
            }
        }
        return root;
    }
};
```