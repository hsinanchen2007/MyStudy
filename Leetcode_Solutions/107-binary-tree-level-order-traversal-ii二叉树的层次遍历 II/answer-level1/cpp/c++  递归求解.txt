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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root==NULL)
            return res;
        vector<TreeNode*> v;
             
        v.push_back(root);
        recur(v,res);
        vector<vector<int>> res1;
        for(int i=res.size()-1;i>=0;i--)
        {
            res1.push_back(res[i]);
        }
        return res1;
    }
    void recur(vector<TreeNode*> tree_node,vector<vector<int>> &res)
    {
        vector<int>temp;
        vector<TreeNode*> v_tn;
        for(int i=0;i<tree_node.size();i++)
        {
            if(tree_node[i]!=NULL)
            {
                v_tn.push_back(tree_node[i]->left);
                v_tn.push_back(tree_node[i]->right);
                temp.push_back(tree_node[i]->val);
            }
        }
        if(v_tn.size())
        {
            res.push_back(temp);
            recur(v_tn,res);
        }  
    } 
};
```
