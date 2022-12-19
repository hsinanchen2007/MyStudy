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
        
        vector<vector<int>> vec;
        queue<pair<TreeNode*,int> > Q;
        if(root)
            Q.push(make_pair(root,0));

        while(!Q.empty())
        {
            vector<int> temp_vec;
            TreeNode* temp = Q.front().first;
            int depth = Q.front().second;
            Q.pop();

            if(vec.size() == depth)
                vec.push_back(temp_vec);
            vec[depth].push_back(temp->val); 
              
            if(temp->left)
                Q.push(make_pair(temp->left , depth + 1));
            if(temp->right)
                Q.push(make_pair(temp->right , depth + 1));
        }
        return vec;
    }
};