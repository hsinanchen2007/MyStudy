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
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        if(!root)return ans;
        q.push(root);
        while(!q.empty()){
            TreeNode* e=q.front();
            q.pop();
            ans.push_back(e->val);
            if(e->left){
                q.push(e->left);
            }
            if(e->right){
                q.push(e->right);
            }
        }
        return ans;
    }
};
```