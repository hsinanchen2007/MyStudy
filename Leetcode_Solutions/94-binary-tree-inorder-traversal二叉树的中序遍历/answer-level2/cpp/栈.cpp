``` c++
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s ;
        vector<int> ans;
        if(!root)return ans;
        TreeNode* t = root;
        while( t!=NULL){
            // cout<<1<<endl;
            while(t->left!=NULL){
                // cout<<2<<endl;
                s.push(t);
                t = t->left;
            }
            ans.push_back(t->val);
            while(t->right==NULL&& !s.empty()){
                // cout<<3<<endl;
                
                t= s.top();
                s.pop();
                ans.push_back(t->val);
                
                
  
            }  
            t = t->right;
        
        }
        return ans;
    }
};
```
