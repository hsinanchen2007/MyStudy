### 解题思路

dfs

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
	vector<vector<int>> ret;
    vector<vector<int>> findLeaves(TreeNode* root) {
        while(root){
            ret.push_back({});
            dfs(root);
        }
        return ret;
    }
    void dfs(TreeNode * &r){
        if(r==NULL)return;
        if(r->left==NULL&&r->right==NULL){
            ret.back().push_back(r->val);
            r=NULL;
            return ;
        }
        dfs(r->left);
        dfs(r->right);
    }
};
```