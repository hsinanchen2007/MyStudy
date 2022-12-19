### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val>q->val){
            return dfs(root,q,p);
        }
        else return dfs(root,p,q);
    }
    TreeNode * dfs(TreeNode *root,TreeNode *p,TreeNode*q){
        if(q->val<root->val){
            return dfs(root->left,p,q);
        }
        else if(p->val>root->val){
            return dfs(root->right,p,q);
        }
        else return root;
    }
};
```