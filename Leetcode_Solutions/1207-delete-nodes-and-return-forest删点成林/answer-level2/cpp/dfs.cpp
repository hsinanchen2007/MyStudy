写的比较水，本题比较简单，也就灌水一下。
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
    bool helper(TreeNode * root,TreeNode * father,int d,vector<TreeNode *> & res,set<int> & target){
        if(!root){ return false;}
        
        if(!father&&!target.count(root->val)){
           res.push_back(root);
        }else if(father&&target.count(father->val)){
           if(!target.count(root->val)){ res.push_back(root);}
        }else if(father&&!target.count(father->val)){
           if(target.count(root->val)){  d == 0? father->left = NULL:father->right = NULL;}
        }
        helper(root->left,root,0,res,target);
        helper(root->right,root,1,res,target);
        if(target.count(root->val)){
            root->left  = NULL;
            root->right = NULL;
        }
        
        return true;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode *> ans;
        set<int> target;
        for(auto d : to_delete){
            target.insert(d);
        }
        helper(root,NULL,0,ans,target);
        return ans;
    }
};
```