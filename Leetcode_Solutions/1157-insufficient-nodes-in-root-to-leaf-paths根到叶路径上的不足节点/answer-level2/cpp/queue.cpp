```
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
  
    
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        set<TreeNode * > detech;
        queue<TreeNode *> qu;
        TreeNode * ans;
        
        /*check every node on the tree*/
        helper(root,limit,detech,0);
        if(detech.count(root)){ return NULL;}
        
        qu.push(root);
        while(!qu.empty()){
            TreeNode * curr = qu.front();
            qu.pop();
            if(curr->left){
                if(detech.count(curr->left)){
                    curr->left = NULL;
                }else{
                    qu.push(curr->left);
                }
            }
            if(curr->right){
                if(detech.count(curr->right)){
                    curr->right = NULL;
                }else{
                    qu.push(curr->right);
                }
            }
        }
        
        return root;
    }
};
```