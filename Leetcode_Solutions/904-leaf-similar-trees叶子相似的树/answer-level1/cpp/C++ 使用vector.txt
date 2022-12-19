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
    void Judge(vector<int> &arr, TreeNode* root){
        if(root!=NULL){
            if(root->left==NULL && root->right==NULL){
                arr.push_back(root->val);
            }
            if(root->left!=NULL){
              Judge(arr, root->left);
            }
            if(root->right!=NULL){
              Judge(arr, root->right);
            }
        }
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL){
            return true;
        }
        if(root1==NULL || root2==NULL){
            return false;
        }
        vector<int> arr1;
        vector<int> arr2;
        
        Judge(arr1, root1);
        Judge(arr2, root2);
        
        if(arr1==arr2){
            return true;
        }
        return false;
    }
};
```