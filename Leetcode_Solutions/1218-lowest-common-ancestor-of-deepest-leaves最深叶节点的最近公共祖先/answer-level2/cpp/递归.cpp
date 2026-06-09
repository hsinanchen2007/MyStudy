如果该节点的左右子树的深度相等，且左右子树的深度均为最大深度，则该节点为目标节点，返回该节点即可，时间复杂度O(n).
另外一种解法，将从根节点到所有最大深度的叶子节点路径存储起来，找到所有路径的最后一个相同的节点，该节点即为最近的父节点。

解法1：
```
* struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int depth(TreeNode * root){
        if(!root){
            return 0;
        }
        int l = depth(root->left);
        int r = depth(root->right);
        return max(l,r)+1;
    }
    
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int l = depth(root->left);
        int r = depth(root->right);
        if(l == r){
            return root;
        }
        if(l > r){
            return lcaDeepestLeaves(root->left);
        }else{
            return lcaDeepestLeaves(root->right);
        }
    }
```
解法2：
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
    int depth(TreeNode * root){
        if(!root){
            return 0;
        }
        
        int l = depth(root->left);
        int r = depth(root->right);
        return max(l,r)+1;
    }
    
    bool deepthestLeaves(TreeNode * root,int d,int curr,vector<TreeNode *> & res){
        if(!root){
            return false;
        }
        
        if(curr == d){
            res.push_back(root);
        }else{
            deepthestLeaves(root->left,d,curr+1,res);
            deepthestLeaves(root->right,d,curr+1,res);
        }
        
        return true;
    }
    
    bool targetPath(TreeNode * root,TreeNode * target,vector<TreeNode *> & path){
        if(!root){
            return false;
        }
        
        if(root == target){
            path.push_back(root);
            return true;
        }else{
            path.push_back(root);
            if(targetPath(root->left,target,path)||
               targetPath(root->right,target,path)){
                return true;
            }else{
                path.pop_back();
                return false;
            }
        }
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int d = 0;
        vector<TreeNode *> target;
        vector<vector<TreeNode *>> treePath;
        TreeNode * res = NULL;
        
        d = depth(root);
        deepthestLeaves(root,d,1,target);
        if(target.size() == 1){
            return target[0];
        }
        
        for(int i = 0;i < target.size(); ++i){
            vector<TreeNode *> path;
            targetPath(root,target[i],path);
            treePath.push_back(path);
        }
        
        for(int i = 0;i < treePath[0].size(); ++i){
            for(int j = 1;j < treePath.size(); ++j){
                if(treePath[j][i] != treePath[j-1][i]){
                    return res;
                }
            }
            res = treePath[0][i];
        }
        
        return res;
    }
};
```