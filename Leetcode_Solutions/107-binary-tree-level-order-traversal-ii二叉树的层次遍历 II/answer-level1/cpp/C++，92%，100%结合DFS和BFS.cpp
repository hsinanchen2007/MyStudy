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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(1+maxDepth(root->left),1+maxDepth(root->right));
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int deep=maxDepth(root);
        vector<vector<int>> a(deep);
        if(root==NULL) return a;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            deep--;
            int num=q.size();
            for(int i=0;i<num;i++){
                TreeNode* p=q.front();
                q.pop();
                int temp=p->val;
                a[deep].push_back(temp);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
        }
        return a;
    }
};