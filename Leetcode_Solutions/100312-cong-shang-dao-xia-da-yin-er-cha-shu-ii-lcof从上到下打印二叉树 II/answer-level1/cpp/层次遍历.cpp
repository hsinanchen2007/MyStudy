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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        queue<TreeNode*> q;
        TreeNode* last=root;
        TreeNode *newlast=root;
        q.push(root);
        vector<int> v;
        while(!q.empty()){
            TreeNode* e=q.front();
            q.pop();
            v.push_back(e->val);
            if(e->left){
                q.push(e->left);
                newlast=e->left;
            }
            if(e->right){
                q.push(e->right);
                newlast=e->right;
            }
            if(e==last){
                ans.push_back(v);
                v.clear();
                last=newlast;
            }
        }
        return ans;
    }
};
```