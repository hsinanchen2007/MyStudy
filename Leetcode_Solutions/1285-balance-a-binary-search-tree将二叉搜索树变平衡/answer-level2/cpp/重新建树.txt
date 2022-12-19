```c++
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
    bool preOrderBst(TreeNode * root,vector<TreeNode *> & nodes){
        if(!root) return false;
        preOrderBst(root->left,nodes);
        nodes.push_back(root);
        preOrderBst(root->right,nodes);
        return false;
    }
    
    TreeNode * buildBst(vector<TreeNode *> & nodes,int l,int r){
        if(l > r) return NULL;
        int mid = (l+r)>>1;
        nodes[mid]->left = buildBst(nodes,l,mid-1);
        nodes[mid]->right = buildBst(nodes,mid+1,r);
        return nodes[mid];
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode *> nodes;
        preOrderBst(root,nodes);
        return buildBst(nodes,0,nodes.size()-1);
    }
};
```