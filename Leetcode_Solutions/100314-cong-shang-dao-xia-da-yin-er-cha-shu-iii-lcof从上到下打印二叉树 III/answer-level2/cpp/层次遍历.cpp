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
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(!root)return ans;
        TreeNode* last=root;
        TreeNode* newlast=root;
        vector<int> v;
        q.push(root);
        int i=0;
        while(!q.empty()){
            TreeNode* e=q.front();
            q.pop();
            v.push_back(e->val);
            if(e->left){
                newlast=e->left;
                q.push(e->left);
            }
            if(e->right){
                newlast=e->right;
                q.push(e->right);
            }
            if(e==last){
                if(i%2==1){
                    reverse(v.begin(),v.end());
                }
                ans.push_back(v);
                last=newlast;
                v.clear();
                i++;
            }
        }
        return ans;
    }
};
```