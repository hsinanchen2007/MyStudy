```
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
# */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*>s,s1;vector<vector<int>>vi;
        vector<int>v;
        if(!root)return vi;
        s.push(root);
        while(!s.empty())
        {
             root=s.front();s.pop();
             v.push_back(root->val);
             if(s.empty()){vi.push_back(v);v={};}
             if(root->left)s1.push(root->left);
             if(root->right)s1.push(root->right);
             if(s.empty()){s=s1;s1=queue<TreeNode*>{};}
          
        }
        reverse(vi.begin(),vi.end()); 
        return vi;
    }
};
```
