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
    bool isValidBST(TreeNode* root) {
        vector<int>a;
        inorder(root,a);
        for(int i=1;i<a.size();i++){
            if(a[i]>a[i-1])；//如果有序，什么都不做
            else return false;//如果逆序，返回false
        }
        return true;
    }
    void inorder(TreeNode*root,vector<int>&a){
        if(root==NULL)return;
        inorder(root->left,a);
        a.push_back(root->val);//记录中序遍历的结果
        inorder(root->right,a);
    }
    
};