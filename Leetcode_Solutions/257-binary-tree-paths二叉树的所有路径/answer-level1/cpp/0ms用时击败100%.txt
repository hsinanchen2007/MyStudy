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
    void visit(TreeNode *root,vector<string>&a,string b)
    {
        if(root==NULL)
            return;
        if(root->left==NULL&&root->right==NULL)
        {          
            b=b+"->"+to_string(root->val);
            b.erase(b.begin());
            b.erase(b.begin());//删除头部多的->
            a.push_back(b);
            return;
        }
        else
        {      
            b=b+"->"+to_string(root->val);    
            visit(root->left,a,b);     
            visit(root->right,a,b);
            return;
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>result;
        string temp;
        if(root==NULL)
        {     
            return result;
        }
        visit(root,result,temp);
        return result;
    }
};
```
